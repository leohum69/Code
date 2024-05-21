
//-----------------------------------------------------------------------------
//                       Group-Members
//                    M. Bilal Ikram (22i-1636)
//                    Humayun Masood (22i-1749)
//                    Mustafa Zain   (22i-4948)
//-----------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <limits>
#include <string>
#include <cstring>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
using namespace std;

#define RESET "\u001B[0m"
#define RED "\u001B[31m"
#define GREEN "\u001B[32m"
#define YELLOW "\u001B[33m"
#define BLUE "\u001B[34m"
#define CYAN "\u001B[36m"

#define SIZE 15
#define CELL_NUMBER 52
#define MAX_PLAYER 4
#define MAX_DE 6
sem_t sem;
//-----------------------------------------------------------------------------
// Objects
//-----------------------------------------------------------------------------

class Cell
{
public:
    int x;
    int y;
    int value;
};

class Player
{
public:
    int x;
    int y;
    int team;
    int index;
    int id;
    int removed;   //killed opponent?
    int position;  // winning position
    bool token_in_house; // tokens in house   
    bool ingame; // is playing game?
    int counter;
    string name;
};
//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
Cell cells[CELL_NUMBER];
Cell houses[MAX_PLAYER][4];
char board[SIZE][SIZE]; // Grid
int n_players = -1;       // No of players
Player players[MAX_PLAYER][4]; // Players
int position = 1;
int winning_position = 1;
int n_tokens=-1;
bool *isfinished = new bool[4];
int *diceroll = new int[3];
//-----------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------
void display();
void initBoard();
void initGame();
void menu(int &);
int play();
void verifyInput();
string idToColor(int);
int getIndexByTurn(int);
bool isFinalWay(int, int, int);
void moveOnFinalWay(Player[MAX_PLAYER][4], int, int);
void displayCurrent();
bool isblock(int , int );
bool is_safepoint(int);
void killtoken(int  , int );
bool choicevalidity(int , int , int );
bool isanymovepossible(int ,int );
void movetoken(int , int , int);
void *createMasterThread(int, int);
void *Masterthread(void *);
void *PlayerThread(void *);
void inputnames()
{
    string Name;
    for(int i=0; i<n_players; i++)
    {
        cout << "Enters Player " << i+1 << "'s Name (Without spaces) : ";
        cin >> Name;
        players[i][0].name = Name;
    }
}
//-----------------------------------------------------------------------------
// Function Definations
//-----------------------------------------------------------------------------
void *PlayerThread(void * arg)
{
        sem_wait(&sem);
        int turn = *(int *) arg;
        int j=0;
        int result;
        for(int i=0; i<3; i++)
        {
            diceroll[i] = 0;
        }
        displayCurrent();
        int choice = -1;
        if(isfinished[turn]!=1)
        {
            cout << endl << ("It's up to player " + idToColor(turn)) << players[turn][0].name << " to play." << RESET << endl;
            j=0;
            do // again turn on case of 6
            {
            result = (rand() % MAX_DE) + 1;
            cout << "Launch of the dice ... Result : " << result << endl;
            diceroll[j] = result;
            j++;
                if(diceroll[2] == 6)
                {
                    cout << "Result : 6,6,6 so, Passing the turn\n";
                    
                    for(int i=0; i<3; i++)
                    {
                        diceroll[i] = 0;
                    }
                    createMasterThread(turn,choice);
                    sem_post(&sem);
                    break;
                }
            }while(result==6); 
        }
        j=0;
        bool is_any_movepossible = isanymovepossible(turn,diceroll[0]);
        if(!is_any_movepossible && players[turn][0].ingame==true)
        {
            players[turn][0].counter++;
        }
        else
        {
            players[turn][0].counter = 0;
        }
        createMasterThread(turn,choice);
        if(!is_any_movepossible)
        {
            sem_post(&sem);
            return NULL;
        }
        while ((is_any_movepossible) && diceroll[j]!=0 && j<3)
        {
            cout << "Which piece do you want to move a throw of " << diceroll[j] << endl << endl;
            cout << ">";
            cin >> choice;
            verifyInput();
            int c;
            c=0;
            while(!choicevalidity(diceroll[j],turn,choice) || c == 4 && isblock(turn,choice))
            {
                cout << "Enter valid token : ";
                cin >> choice;
                verifyInput();
                c++;  // c is used just to be safe in case some unexpected situation occurs
            }
            if(c!=4)
            {
                movetoken(turn,choice,diceroll[j]);
                createMasterThread(turn,choice);
            }
            j++;
        } 
        bool win = true;
        for(int i=0; i<n_tokens; i++)
        {
            if(players[turn][i].index!=106)
            {
                win = false;
            }
        }
        if(win)
        {
            createMasterThread(turn,choice);
        }
    sem_post(&sem);
    return NULL;
}
void *createMasterThread(int turn = 0 , int choice = -1)
{
    pthread_t master;
    pair<int, int> args = make_pair(turn, choice);
    pthread_create(&master, NULL, Masterthread, (void *)&args);
    void *status;
    pthread_join(master, &status);
    return status;
}
void *Masterthread(void * args)
{
    int turn = (*(pair<int, int> *)args).first;
    int choice = (*(pair<int, int> *)args).second;
    // Check & Remove
    if(players[turn][0].counter >= 20)
    {
        cout << "20 consecutive turns without 6 or any move thus player " << turn+1 << " is out of game" << endl;
        players[turn][0].ingame = false;
        players[turn][0].position = -1;
        position++;
        isfinished[turn]=1;
    }
    // kill token and update hit rate(removed)
    for (int i = 0; i < MAX_PLAYER; i++) // kill token
    {
        if (i != turn)
        {
        for (int j = 0; j < n_tokens; j++)
            {
                if (players[i][j].x == players[turn][choice - 1].x && players[i][j].y == players[turn][choice - 1].y && (!(is_safepoint(players[i][j].index))))
                {
                    players[i][j].index = -1;
                    players[i][j].x = houses[i][j].x;
                    players[i][j].y = houses[i][j].y;
                    for(int k=0;k< n_tokens ; k++)
                    {
                    players[turn][k].removed++;
                    }
                }
            }
        }
    }
    // Verifying Win, Assigning Position & Removing
    int count;
    count =0;
    for(int j =0; j< n_tokens; j++)
    {
        if(players[turn][j].index == 106)
        {
            count++;
        }
    }
    if(count == n_tokens && players[turn][0].ingame==true)
    {
        players[turn][0].ingame = false;
        players[turn][0].position = winning_position;
        winning_position++;
        position++;
        isfinished[turn]=1;
    }
    return NULL;
}

bool isblock(int turn, int choice)
{
    int c=0;
    for (int i = 0; i < MAX_PLAYER; i++)
        {
            if (i != turn) 
            {
                for (int j = 0; j < n_tokens; j++)
                {
                    if (players[i][j].x == players[turn][choice-1].x && players[i][j].y == players[turn][choice-1].y && players[i][j].team != players[turn][choice-1].team)// on same square
                    {                                     
                        if (is_safepoint(players[i][j].index)) // not safe
                        {
                            c++;
                        }
                        if (c >= 2) // check block;
                        {
                            return true;
                        }
                    }
                }
            }
        }
    return false;
}
bool is_safepoint(int index)
{
    if((index == 0)||(index == 8)||(index == 13)||(index == 21)||(index == 26)||(index == 34)|| (index == 39) || (index == 47))
    {
        return true;
    }
    return false;
}
bool isanymovepossible(int turn,int result)
{
    if(isfinished[turn]==1 || result == 0)
    {
        return false;
    }
    bool check = false;
    for(int i=0; i<n_tokens; i++)
    {
        if(players[turn][i].index ==-1)
        {
            check = true;
        }
    }
    if(result == 6 && check == true)
    {
        return true;
    }
    else
    {
        for(int i=0; i<n_tokens; i++)
        {
            if(players[turn][i].index!=-1 && players[turn][i].index!=106 && ((players[turn][i].index + result) <=106))
            {
                return true;
            }
        }
        return false;
    }
}
void movetoken(int turn, int choice, int result)
{
    if (players[turn][choice - 1].index == -1 && result == 6)
        {
            players[turn][choice - 1].index = getIndexByTurn(turn);
            players[turn][choice - 1].x = cells[getIndexByTurn(turn)].x;
            players[turn][choice - 1].y = cells[getIndexByTurn(turn)].y;
        }
        else if (players[turn][choice - 1].index != -1)
        {
            int step = result;
            while (step > 0)
            {
                if (isFinalWay(turn, choice, players[turn][choice - 1].index))
                {
                    players[turn][choice - 1].index = 100;
                }
                if (players[turn][choice - 1].index < CELL_NUMBER)
                {
                    players[turn][choice - 1].index = (players[turn][choice - 1].index + 1) % CELL_NUMBER;
                    players[turn][choice - 1].x = cells[players[turn][choice - 1].index].x;
                    players[turn][choice - 1].y = cells[players[turn][choice - 1].index].y;
                }
                else
                {
                    players[turn][choice - 1].index = players[turn][choice - 1].index + 1;
                    moveOnFinalWay(players, turn, choice);
                    if (players[turn][choice - 1].x == 5 && players[turn][choice - 1].y == 5)
                    {
                        displayCurrent();
                    }
                }
                step--;
            }
        }
}
bool choicevalidity(int res, int turn, int choice)
{
    if(choice < 1 || choice > 4 || choice > n_tokens)
    {
        return false;
    }
    else if((res!=6 && (players[turn][choice - 1].index == -1)) || (((players[turn][choice-1].index)+res)>106))
    {
        return false;
    }
    else
    {
        return true;
    }
}


//-----------------------------------------------------------------------------
// MAIN
//-----------------------------------------------------------------------------
int main()
{
    sem_init (&sem , 0 , 1 );
    srand(time(NULL));
    initBoard();
    while (true)
    {
        int choice;
        choice = -1;
        menu(choice);

        if (choice == 2)
        {
            cout << endl
                 << "Stopping the game ..." << endl;
            return 0;
        }
        else
        {
            play();
            display();
        }
    }

    return 0;
}

//-----------------------------------------------------------------------------
// INIT
//-----------------------------------------------------------------------------
void display()
{
    cout << endl << endl << "-------------Displaying Result of the Game---------------" << endl << endl << endl;
    cout << "Number of Tokens : " << n_tokens << endl << endl << endl;
    for(int i=0; i<n_players; i++)
    {
        cout << "Player " << i+1 << "'s Name : " << players[i][0].name << endl;
        if(players[i][0].position == -1)
        {
            cout << "Player " << i+1 << "'s Position : None (out of Game)" << endl;
        }
        else if(players[i][0].position == n_players)
        {
            cout << "Player " << i+1 << "'s Position : Last " << endl;
        }
        else
        {
        cout << "Player " << i+1 << "'s Position : " << players[i][0].position << endl;
        }    
        cout << "Player " << i+1 << "'s Hit Rate : " << players[i][0].removed << endl;
        cout << endl << endl ;
    }
}
void initBoard()
{
    char newBoard[SIZE][SIZE] = {
       {' ',' ',' ',' ',' ',' ','O','O','O',' ',' ',' ',' ',' ',' '},
       {' ',' ',' ',' ',' ',' ','O','g','g',' ',' ',' ',' ',' ',' '},
       {' ',' ','r','r',' ',' ','g','g','O',' ',' ','g','g',' ',' '},
       {' ',' ','r','r',' ',' ','O','g','O',' ',' ','g','g',' ',' '},
       {' ',' ',' ',' ',' ',' ','O','g','O',' ',' ',' ',' ',' ',' '},
       {' ',' ',' ',' ',' ',' ','O','g','O',' ',' ',' ',' ',' ',' '},
       {'O','r','O','O','O','O',' ',' ',' ','O','O','O','b','O','O'},
       {'O','r','r','r','r','r',' ','H',' ','b','b','b','b','b','O'},
       {'O','O','r','O','O','O',' ',' ',' ','O','O','O','O','b','O'},
       {' ',' ',' ',' ',' ',' ','O','y','O',' ',' ',' ',' ',' ',' '},
       {' ',' ',' ',' ',' ',' ','O','y','O',' ',' ',' ',' ',' ',' '},
       {' ',' ','y','y',' ',' ','O','y','O',' ',' ','b','b',' ',' '},
       {' ',' ','y','y',' ',' ','O','y','y',' ',' ','b','b',' ',' '},
       {' ',' ',' ',' ',' ',' ','y','y','O',' ',' ',' ',' ',' ',' '},
       {' ',' ',' ',' ',' ',' ','O','O','O',' ',' ',' ',' ',' ',' '},
    }; // Ludo board is 15x15

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = newBoard[i][j];
        }
    }
}
void initGame()
{

    int newCells[CELL_NUMBER][2] = {
        {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5},
        {5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6},{0,7},
        {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8},
        {6, 9}, {6, 10}, {6, 11}, {6, 12}, {6, 13}, {6, 14},{7, 14},
        {8, 14}, {8, 13}, {8, 12}, {8, 11}, {8, 10}, {8, 9},
        {9, 8}, {10, 8}, {11, 8}, {12, 8}, {13, 8}, {14, 8}, {14, 7},
        {14, 6}, {13, 6}, {12, 6}, {11, 6}, {10, 6}, {9, 6},
        {8, 5}, {8, 4}, {8, 3}, {8, 2}, {8, 1}, {8, 0}, {7, 0},{6,0} };
    int newHouses[MAX_PLAYER][4][2] = 
    {
        {{2, 2}, {2, 3}, {3, 3}, {3, 2}},
        {{2, 11}, {2, 12}, {3, 12}, {3, 11}},
        {{11, 11}, {11, 12}, {12, 12}, {12, 11}},
        {{11, 2}, {11, 3}, {12, 3}, {12, 2}},
    };

    for (int i = 0; i < CELL_NUMBER; i++)
    {
        cells[i].y = newCells[i][0];
        cells[i].x = newCells[i][1];
        cells[i].value = 0;
    }

    for (int i = 0; i < MAX_PLAYER; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            houses[i][j].y = newHouses[i][j][0];
            houses[i][j].x = newHouses[i][j][1];
            houses[i][j].value = (j + 1) + (i) * 10;
        }
    }

    for (int i = 0; i < MAX_PLAYER; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            players[i][j].x = houses[i][j].x;
            players[i][j].y = houses[i][j].y;
            players[i][j].index = -1;
            players[i][j].team = i;
            players[i][j].id = j + 1;
            players[i][j].removed = 0;
            players[i][j].position=n_players;
            players[i][j].counter = 0;
            if(i < n_players)
            {
                players[i][j].ingame = true;
            }
            else
            {
                players[i][j].ingame = false;
            }
        }
    }
}

//-----------------------------------------------------------------------------
// MENU + PLAY
//-----------------------------------------------------------------------------

void menu(int &choice)
{
    while (choice > 2 || choice < 1)
    {
        cout << endl
             << "1 - To Play" << endl;
        cout << "2 - To Quit " << endl
             << endl
             << ">";
        cin >> choice;
        verifyInput();
    }

    if (choice == 1)
    {
        while (n_players < 2 || n_players > 4)
        {
            cout << endl
                 << "How many players (between 2 and 4) ?" << endl
                 << endl
                 << ">";
            cin >> n_players;
            verifyInput();
        }
        while (n_tokens < 1 || n_tokens > 4)
        {
            cout << endl
                 << "How many tokens (between 1 and 4) ?" << endl
                 << endl
                 << ">";
            cin >> n_tokens;
            verifyInput();
        }
    }
}

int play()
{
    initGame();
    inputnames();
    bool *visited = new bool[n_players];
    int counter=1;       // random turn
    int *turn = new int;   
    *turn = rand()%n_players;
    visited[*turn]=1;
    for(int i=0; i<n_players; i++) 
    {
        isfinished[i]=0;
        visited[i]=0;
        if(i<3)
        {
            diceroll[i] = 0;
        }
    }
    cout<<"Game Started"<<endl;
    pthread_t Playthreads[4];
    srand(time(NULL));
    while (position != n_players)
    {
        for (int i = 0; i < n_players; i++)
        {
            sleep(1);
            pthread_create(&Playthreads[i], NULL, PlayerThread, turn);
            if(counter == n_players)      // Random turn
            {
                counter = 0;
                for(int i=0; i<n_players; i++)
                    {   
                        visited[i]=0;
                    }
            }
            do
            {
                *turn = rand()%n_players;
            }while(visited[*turn]==1);
            visited[*turn]=1;
            counter++;
        }
        for (int i = 0; i < n_players; i++)
        {
            pthread_join(Playthreads[i], NULL);
        }
       
    }
    
    return 0;
}

//-----------------------------------------------------------------------------
// UTILS
//-----------------------------------------------------------------------------

void verifyInput()
{
    if (!cin)
    {
        cout << "ERROR - Enter a valid number";

        cin.clear();

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

string idToColor(int id)
{
    switch (id)
    {
    case 0:
        return RED;
    case 1:
        return GREEN;
    case 2:
        return CYAN;
    case 3:
        return YELLOW;
    default:
        return "";
    }
    return "";
}

int getIndexByTurn(int turn)
{
    return turn * 13;
}

bool isFinalWay(int turn,int choice, int index)
{
    switch (turn)
    {
    case 0:
        if (index == 50 && players[turn][choice-1].removed >0)
            return true; 
        return false;

    case 1:
        if (index == 11 && players[turn][choice-1].removed >0)
            return true;
        return false;
    case 2:
        if (index == 24 && players[turn][choice-1].removed >0)
            return true;
        return false;
    case 3:
        if (index == 37 && players[turn][choice-1].removed >0)
            return true;
        return false;
    }
    return false;
}

void moveOnFinalWay(Player players[MAX_PLAYER][4], int turn, int choice)
{
    switch (turn)
    {
    case 0:
        players[turn][choice - 1].x += 1;
        break;
    case 2:
        players[turn][choice - 1].x -= 1;
        break;
    case 1:
        players[turn][choice - 1].y += 1;
        break;
    case 3:
        players[turn][choice - 1].y -= 1;
        break;
    }
}

//-----------------------------------------------------------------------------
// DISPLAY functions
//-----------------------------------------------------------------------------

void displayCurrent()
{
    char currentBoard[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            currentBoard[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < MAX_PLAYER; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            currentBoard[players[i][j].y][players[i][j].x] = '0' + players[i][j].id;
        }
    }

    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << " ";
        for (int j = 0; j < SIZE; j++)
        {
            string s = "";
            s = s + currentBoard[i][j] + " ";

            switch (currentBoard[i][j])
            {
            case 'r':
                s = "O ";
                s = RED + s + RESET;
                break;
            case 'g':
                s = "O ";
                s = GREEN + s + RESET;
                break;
            case 'b':
                s = "O ";
                s = CYAN + s + RESET;
                break;
            case 'y':
                s = "O ";
                s = YELLOW + s + RESET;
                break;
            case '1':
            case '2':
            case '3':
            case '4':
                s = "";
                s = s + currentBoard[i][j] + " ";
                for (int a = 0; a < MAX_PLAYER; a++)
                {
                    for (int b = 0; b < 4; b++)
                    {
                        if (i == players[a][b].y && j == players[a][b].x)
                        {
                            switch (players[a][b].team)
                            {
                            case 0:
                                s = RED + s + RESET;
                                break;
                            case 1:
                                s = GREEN + s + RESET;
                                break;
                            case 2:
                                s = CYAN + s + RESET;
                                break;
                            case 3:
                                s = YELLOW + s + RESET;
                                break;
                            }
                        }
                    }
                }
                break;
            }
            cout << s;
        }
        cout << endl;
    }
    cout << endl;
}
