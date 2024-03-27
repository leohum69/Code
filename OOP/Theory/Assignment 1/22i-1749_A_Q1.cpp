/*
Name: Mirza Humayun Masood
Roll No: 22i-1749
Assignment No 1.
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void menu(int**** p);
int**** init(int dimension);
void reward_loc(int**** p,int dim);
void play_game(int**** p,int dim);
void dist(int**** p,int dim,int x,int y,int z);
void scoring(int**** p,int dim,int x,int y,int z,int time,double* score);
int main(){
    srand(time(NULL));
    int**** p=0;
    menu(p);                //caling menu functiion




return 0;
}
void menu(int**** p){               //in menu, it have all three functions
    int dim=0;
    int choice=0;
    bool check=false;
    while(choice != 4){
        cout<<"Menu"<<endl;
        cout<<"1-Initialize The Matrix with new Rewards."<<endl;
        cout<<"2-Print Matrix(For Seeing Reward Locations)."<<endl;
        cout<<"3-Play Game."<<endl;
        cout<<"4-Exit."<<endl;
        cout<<"Enter Numbers to choose option:";
        cin>>choice;
        if(choice == 1)
            check=true;
        if(choice == 1){
            cout<<"Enter The Dimension of The Matrix: ";
            cin>>dim;
            p=init(dim);            //initialzing call
        }else if(choice == 2 && (check==true)){
            reward_loc(p,dim);      //reward print call
        }else if(choice == 3 && (check==true)){
            play_game(p,dim);        //play game call
        }else if(choice == 4){
            break;      //break
        }else{
            cout<<"Wrong Input"<<endl;
        }
    }
                //deleting

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            for(int k=0;k<dim;k++){
                delete []*(*(*(p+i)+j)+k);
            }
        }
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            delete []*(*(p+i)+j);
        }
    }
    for(int i=0;i<dim;i++){
        delete []*(p+i);
    }
    delete []p;

}
int**** init(int dimension){                //initializing space
    int**** p= new int***[dimension];
    for(int i=0;i<dimension;i++){
        *(p+i)= new int**[dimension];
        for(int j=0;j<dimension;j++){
            *(*(p+i)+j)= new int*[dimension];
            for(int k=0;k<dimension;k++){
                *(*(*(p+i)+j)+k)=new int[3];
                for(int l=0;l<3;l++){
                    *(*(*(*(p+i)+j)+k)+l)=0;
                }
            }
        }
    }
    int rewards_num= ((dimension*dimension*dimension*3)*40)/100;  //change later reward
    int c=0;
    int i,j,k,l;
    while(c<rewards_num){
        i=rand()%dimension;
        j=rand()%dimension;
        k=rand()%dimension;
        l=rand()%3;
        *(*(*(*(p+i)+j)+k)+l)=1;
        c++;
    }
    return p;
}
void reward_loc(int**** p,int dim){                                         //locations of reward
    int c=1;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            for(int k=0;k<dim;k++){
                for(int l=0;l<3;l++){
                    if(*(*(*(*(p+i)+j)+k)+l) == 1){
                        cout<<"Reward_"<<c<<" : "<<i<<","<<j<<","<<k<<",";
                        if(l==0)
                            cout<<" PAST";
                        else if(l==1)
                            cout<<"PRESENT";
                        else if(l==2)
                            cout<<"FUTURE";
                        cout<<endl;
                        c++;
                    }
                }
            }
        }
    }
}
void play_game(int**** p,int dim){              //play game
    int moves=0;
    double score=0;
    int x,y,z,time;
    cout<<"Enter The Number of Moves You want to Move:";
    cin>>moves;
    int c=1;
    while(c<=moves){                //number of moves
        cout<<"Moves: "<<c<<endl;
        cout<<"Enter The Point You want to move at"<<endl;
        cout<<"Enter Time,(0 for Past,1 for Present,2 for Future):";
        cin>>time;
        while(time < 0 || time > 2){
            cout<<"Wrong Input"<<endl;
            cout<<"Enter Time,(0 for Past,1 for Present,2 for Future):";
            cin>>time;
        }
        cout<<"Enter The value of x-coordinate:";
        cin>>x;
        while(x < 0 || x > dim-1){
            cout<<"Enter The value of x-coordinate:";
            cin>>x;
        }
        cout<<"Enter The value of y-coordinate:";
        cin>>y;
        while(y < 0 || y > dim-1){
            cout<<"Enter The value of y-coordinate:";
            cin>>y;
        }
        cout<<"Enter The value of z-coordinate:";
        cin>>z;
        while(z < 0 || z > dim-1){
            cout<<"Enter The value of z-coordinate:";
            cin>>z;
        }
        scoring(p,dim,x,y,z,time,&score);               //scoring function
        cout<<"Scores: "<<score<<endl;
        dist(p,dim,x,y,z);                      //distance function
        c++;
    }

}
void dist(int**** p,int dim,int x,int y,int z){         //distance
    int c=1;
    int distance=0;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            for(int k=0;k<dim;k++){
                for(int l=0;l<3;l++){
                    if(*(*(*(*(p+i)+j)+k)+l) == 1){
                        distance=sqrt(pow(i-x,2) + pow(j-y,2) + pow(k-z,2));
                        cout<<"Reward_"<<c<<": Distance is "<<distance<<endl;
                        c++;
                        distance=0;
                    }
                }
            }
        }
    }
}
void scoring(int**** p,int dim,int x,int y,int z,int time,double* score){               //scoring function
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            for(int k=0;k<dim;k++){
                for(int l=0;l<3;l++){
                    if(*(*(*(*(p+i)+j)+k)+l) == 1){
                        if(i==x && j==y && z== k){
                            if(time==l){
                                cout<<"You Guessed it Right(Awarded Score 1)"<<endl;
                                *score= *score + 1;
                                *(*(*(*(p+i)+j)+k)+l)=0;
                            }else{
                                cout<<"You Guessed the location Right but the time wasn't it (Score 0.5)"<<endl;
                                *score = *score + 0.5;
                                *(*(*(*(p+i)+j)+k)+l)=0;
                            }
                        }
                    }
                }
            }
        }
    }
}
