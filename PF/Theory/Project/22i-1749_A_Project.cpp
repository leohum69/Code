/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;
    void readf(string arr[][3],float newprice[]);      //function Prototypes
	float change(string);
	int cc(char);
    void cals(string xd,string xd2, int p);
    void draw(string arr[][3],float prices[],float newprices[],float low[],float high[],int &sharedstocks);
    void change(float prices[],float high[],float low[],float newprices[]);
    bool port();
    void makeport(string &user,float &balance);
    void Showport(string arr[][3],float prices[],float newprices[],float low[],float high[],float &balance,int stocks[],string &user,float &prevbalance,float gl[]);
    void Addstock(string arr[][3],float newprices[],float &balance,int stocks[],int &sharedstocks);
    void remstock(string arr[][3],float newprices[],float &balance,int stocks[],int &sharedstocks);
    void Addmoney(float &balance);
    void Remmoney(float &balance);
    void gainloss(float prices[],float newprices[],float gl[]);
    void writerport(string arr[][3],float prices[],float newprices[],float low[],float high[],float &balance,int stocks[],string &user,float &prevbalance,float gl[]);
    void readport(string &user,float &prevbalance,float &balance,int stocks[],string arr[][3],float prices[],float newprices[]);
    void writemarket(string arr[][3],float newprices[]);
    int top(float prices[],float low[]);
    int lowes(float prices[],float high[]);


int main(){
	float balance=0,prevbalance=0;
    int a=1;
    char val;
    string user;
    srand(time(0));
    string arr[38][3];      //variable declaration
    float prices[37]={0};
    float high[37]={0};
    float low[37]={0};
    float newprices[37]={0};
    int stocks[37]={0};
    float gl[37]={0};
    int sharedstocks=0;
    readf(arr,newprices);                           //reading from companies.txt
    if(port())
        readport(user,prevbalance,balance,stocks,arr,prices,newprices);         //reading portfolio file
    draw(arr,prices,newprices,low,high,sharedstocks);       //drawing the market
    val=getch();
    while(val!='e' && val!='E'){            //while loop
        switch(val){            //switch Cases
            case 'L':
            case 'l':
                system("CLS");
                draw(arr,prices,newprices,low,high,sharedstocks);
                a=1;
                val=getch();
                break;
            case ' ':
                change(prices,high,low,newprices);
                system("CLS");
                if(a==1)
                    draw(arr,prices,newprices,low,high,sharedstocks);
                else if(a==2){
                    gainloss(prices,newprices,gl);
                    Showport(arr,prices,newprices,low,high,balance,stocks,user,prevbalance,gl);
                }
                val=getch();
                break;
            case 'O':
            case 'o':
                system("CLS");
                if(!port())
                    makeport(user,balance);
                else
                    cout<<"Invalid Input"<<endl;
                system("CLS");
                if(a==1)
                    draw(arr,prices,newprices,low,high,sharedstocks);
                val=getch();
                break;
            case 'A':
            case 'a':
                system("CLS");
            	if(!port()){
                    cout<<"Invalid Input"<<endl;
                    cout<<"First Make A Portfolio."<<endl;
            	}else{
            		prevbalance = balance;
            		Addstock(arr,newprices,balance,stocks,sharedstocks);
				}
				system("CLS");
                if(a==1)
                    draw(arr,prices,newprices,low,high,sharedstocks);
                else if(a==2){
                    gainloss(prices,newprices,gl);
                    Showport(arr,prices,newprices,low,high,balance,stocks,user,prevbalance,gl);
                }
                val=getch();
				break;
			case 'R':
            case 'r':
			    system("CLS");
            	if(!port()){
                    cout<<"Invalid Input"<<endl;
                    cout<<"First Make A Portfolio."<<endl;
            	}else{
            		prevbalance = balance;
            		remstock(arr,newprices,balance,stocks,sharedstocks);
				}
				system("CLS");
                if(a==1)
                    draw(arr,prices,newprices,low,high,sharedstocks);
                else if(a==2){
                    gainloss(prices,newprices,gl);
                    Showport(arr,prices,newprices,low,high,balance,stocks,user,prevbalance,gl);
                }
				val=getch();
				break;
			case 'M':
            case 'm':
			    system("CLS");
            	if(!port()){
                    cout<<"Invalid Input"<<endl;
                    cout<<"First Make A Portfolio."<<endl;
            	}else{
            		prevbalance = balance;
            		Addmoney(balance);
				}
				system("CLS");
                if(a==1)
                    draw(arr,prices,newprices,low,high,sharedstocks);
                else if(a==2){
                    gainloss(prices,newprices,gl);
                    Showport(arr,prices,newprices,low,high,balance,stocks,user,prevbalance,gl);
                }
				val=getch();
				break;
			case 'W':
            case 'w':
			    system("CLS");
            	if(!port()){
                    cout<<"Invalid Input"<<endl;
                    cout<<"First Make A Portfolio."<<endl;
            	}else{
            		prevbalance = balance;
            		Remmoney(balance);
				}
				system("CLS");
                if(a==1)
                    draw(arr,prices,newprices,low,high,sharedstocks);
                else if(a==2){
                    gainloss(prices,newprices,gl);
                    Showport(arr,prices,newprices,low,high,balance,stocks,user,prevbalance,gl);
                }
				val=getch();
				break;
            case 'P':
            case 'p':
                system("CLS");
                if(!port()){
                    cout<<"Invalid Input"<<endl;
                    cout<<"First Make A Portfolio."<<endl;
            	}else{
            	    gainloss(prices,newprices,gl);
            	    Showport(arr,prices,newprices,low,high,balance,stocks,user,prevbalance,gl);
            	    a=2;
            	    val=getch();
				}
            case 'E':
            case 'e':
                break;
                break;
            default:
                cout<<"Invalid Input"<<endl;
                val=getch();
                break;
        }
    }

    if(port())
        writerport(arr,prices,newprices,low,high,balance,stocks,user,prevbalance,gl);       //writin portfolio at the end
    writemarket(arr,newprices);               //writin  companies at the end






return 0;
}
int cc(char l){     //function for string to float (part 1)
	switch(l){
		case '1':
			return 1;
		break;
		case '2':
			return 2;
		break;
		case '3':
			return 3;
		break;
		case '4':
			return 4;
		break;
		case '5':
			return 5;
		break;
		case '6':
			return 6;
		break;
		case '7':
			return 7;
		break;
		case '8':
			return 8;
		break;
		case '9':
			return 9;
		break;
		case '0':
			return 0;
		break;
		default:
			return -1;
			break;
	}

}
float change(string mon){           //function for string to float (part 2)
	int counter=0;
	int i=0;
	int pew=0;
	int intpart=0;
	float floatpart=0;
	float returnwala=0;
	while(mon[i]!='\0'){
		if(mon[i]=='.'){
			pew=counter;
		}
		i++;
		counter++;
	}

	int power=pew-1;
	int low= counter-pew;
	if(pew==0){
	for(int p=0;p<counter;p++){
		returnwala+= (cc(mon[p])*pow(10,counter-1-p));
	}
	}else{
		for(int c=0;c<pew;c++,power--){
			intpart+=(cc(mon[c])*pow(10,power));
		}
		for(int i=(pew+1);i<counter;i++,low--){
			floatpart+=(cc(mon[i])*pow(10,(low-2)));
		}
		low= counter-pew;
		returnwala = intpart + (floatpart/(pow(10,low-1)));
	}
	return returnwala;

}
void readf(string arr[][3],float newprice[]){          //reading vals from file
    ifstream fin;
	fin.open("companies.txt");
	for(int i=0;i<38;i++){
		for(int j=0;j<3;j++){
			if(j==2){
				getline(fin,arr[i][j]);
			}else{
				getline(fin,arr[i][j],',');
			}
		}
	}

	for(int i=0;i<37;i++){
		newprice[i]=change(arr[i+1][2]);
	}

}

void cals(string xd,string xd2, int p){     //for spaces
    int counter=0;
    if(p==1){
        while(xd[counter]!='\0'){
            counter++;
        }

        for(int i=0;i<(8-counter);i++){
            cout<<" ";
        }
    }else if(p==2){
        while(xd2[counter]!='\0'){
            counter++;
        }
        for(int i=0;i<(34-counter);i++){
            cout<<" ";
        }
    }else if(p==3){
        while(xd2[counter]!='\0'){
            counter++;
        }
        for(int i=0;i<(25-counter);i++){
            cout<<" ";
        }

    }

}
void draw(string arr[][3],float prices[],float newprices[],float low[],float high[],int &sharedstocks){       //draw market
    static int pp=1;
    int topindex=0,lowindex=0;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( h, 31);
    cout<<setw(53)<<"Karachi Stock Market (Live)"<<setw(27)<<" "<<endl;
    SetConsoleTextAttribute ( h, 14);
    cout<<"Show updates:"<<static_cast<char>(9166)<<" |";
    if(port())
        cout<<"Show Portfolio:P";
    else
        cout<<"Make Portfolio:O";
    cout<<" |"<<"Add Stock:A"<<"|"<<"Remove Stock:R"<<"|"<<"Add money:M"<<" |"<<"Exit:E"<<endl;
    SetConsoleTextAttribute ( h, 240);
    cout<<"Stocks"<<setw(15)<<"Company Name"<<setw(29)<<"Prev price"<<" "<<"Curr Price"<<"   "<<"High"<<"   "<<"Low      "<<endl;
    for(int i=1;i<38;i++){
        cout<<fixed<<arr[i][0];
        cals(arr[i][0],arr[i][1],1);
        cout<<arr[i][1];
        cals(arr[i][0],arr[i][1],2);
        cout<<setprecision(2)<<prices[i-1];
        if(pp==1){
            cout<<setw(11)<<newprices[i-1];
        }else{
            if(newprices[i-1]>prices[i-1]){
                SetConsoleTextAttribute ( h, 250);
                cout<<setw(11)<<newprices[i-1];
                SetConsoleTextAttribute ( h, 240);
            }else if(newprices[i-1]<prices[i-1]){
                SetConsoleTextAttribute ( h, 252);
                cout<<setw(11)<<newprices[i-1];
                SetConsoleTextAttribute ( h, 240);
            }else{
                cout<<setw(11)<<newprices[i-1];
            }
        }
        cout<<setw(10)<<high[i-1]<<setw(10)<<low[i-1];

        cout<<endl;
    }
    pp++;
    topindex = top(prices,low);
	lowindex = lowes(prices,high);
    cout<<"Total shares traded today : "<<sharedstocks<<endl;
    SetConsoleTextAttribute ( h, 250);
    cout<<"Top % advancer symbol : "<<arr[topindex][0]<<endl;
    SetConsoleTextAttribute ( h, 252);
    cout<<"Top % decliner symbol : "<<arr[lowindex][0]<<endl;
    SetConsoleTextAttribute ( h, 240);

}
void change(float prices[],float high[],float low[],float newprices[]){     //update values

    int luck=0;
    float cc=0;
    float x=0;
    static int pp=1;
    for(int i=0;i<37;i++){
        prices[i]=newprices[i];
    }


    for(int i=0;i<37;i++){
        luck = rand()%2;
        x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/15));
        cc = static_cast<float>((prices[i]*x))/static_cast<float>(100);
        if(luck){
            newprices[i]= prices[i] - cc;
        }else{
            newprices[i]= prices[i] + cc;
        }
    }
    if(pp==1){
        for(int i=0;i<37;i++){
            high[i]= prices[i];
            low[i]= prices[i];
        }
        pp++;
    }
    for(int i=0;i<37;i++){
        if(high[i] < newprices[i]){
            high[i]=newprices[i];
        }
        if(low[i] > newprices[i]){
            low[i]=newprices[i];
        }
    }
}
bool port(){        //for portfolio
    ifstream fin;
    fin.open("portfolio.txt");
    if(!fin){
       return false;
    }else{
        return true;
    }
    fin.close();


}
void makeport(string &user,float &balance){       //making portfolio
    system("CLS");
    cout<<"Enter Your Name: ";
    getline(cin,user);
    cout<<"Enter Your Starting Money: ";
    cin>>balance;
    ofstream fout;
    fout.open("portfolio.txt");
    fout.close();
}
void Addmoney(float &balance){			//add money
	int x;
	cout<<"You Currently Have "<<balance<<" Pkr."<<endl;
	cout<<"Enter Money You want to add: ";
	cin>>x;
	while(x<0){
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Money Again: ";
		cin>>x;
	}
	balance = x + balance;

}
void Remmoney(float &balance){			//remove money
	int x;
	cout<<"You Currently Have "<<balance<<" Pkr."<<endl;
	cout<<"Enter Money You want to Withdraw: ";
	cin>>x;
	while(x<0 || x>balance){
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Money Again: ";
		cin>>x;
	}
	balance = balance-x;
}
void Addstock(string arr[][3],float newprices[],float &balance,int stocks[],int &sharedstocks){		//add  stocks
	bool check=false;
	string symbol;
	int shares;
	int index=-1;
	cout<<"Enter Symbol of The Company You want Shares to Buy: ";
	cin>>symbol;
	for(int i=1;i<38;i++){
		if(symbol==arr[i][0]){
			check=true;
		}
	}
	while(!check){
		cout<<"Invalid Input";
		cout<<"Enter Symbol Again: ";
		cin>>symbol;
	for(int i=1;i<38;i++){
		if(symbol==arr[i][0]){
			check=true;
		}
	}
}


	for(int i=1;i<38;i++){
		if(symbol==arr[i][0]){
			index=i;
		}
	}
	cout<<"How Much Shares You want To Buy: ";
	cin>>shares;
	while(shares<0){
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Number of Shares Again: ";
		cin>>shares;
	}
	int x=balance;

	while((newprices[index-1]*shares)>x){
		cout<<"Invalid Input"<<endl;
		cout<<"You Dont have Enough Money."<<endl;
		cout<<"Enter Number of Shares Again: ";
		cin>>shares;
	}

	stocks[index-1]= stocks[index-1] + shares;
	sharedstocks =  sharedstocks + shares;
	balance = balance - (stocks[index-1]*newprices[index-1]);
}
void remstock(string arr[][3],float newprices[],float &balance,int stocks[],int &sharedstocks){		//rem stocks
	bool check=false;
	string symbol;
	int shares;
	int index=-1;
	cout<<"These are the Companies and Their Stocks You have Bought."<<endl;
	for(int i=0;i<37;i++){
        if(stocks[i]!= 0 ){
            cout<<arr[i+1][0];
            cals(arr[i+1][0],arr[i+1][1],1);
            cout<<arr[i+1][1];
            cals(arr[i+1][0],arr[i+1][1],3);
            cout<<stocks[i]<<endl;
        }
    }
	cout<<"Enter Symbol of The Company You want Shares to Sell: ";
	cin>>symbol;
	for(int i=1;i<38;i++){
		if(symbol==arr[i][0]){
			check=true;
		}
	}
	while(!check){
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Symbol Again: ";
		cin>>symbol;
        for(int i=1;i<38;i++){
            if(symbol==arr[i][0]){
                check=true;
            }
        }
    }


	for(int i=1;i<38;i++){
		if(symbol==arr[i][0]){
			index=i;
		}
	}
	cout<<"How Much Shares You want To Sell: ";
	cin>>shares;
	while(shares<0 || shares>stocks[index-1]){
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Number of Shares Again: ";
		cin>>shares;
	}
	stocks[index-1]= stocks[index-1] - shares;
	sharedstocks =  sharedstocks + shares;
	balance = balance + (stocks[index-1]*newprices[index-1]);
}
void gainloss(float prices[],float newprices[],float gl[]){             //gain loss
    for(int i=0;i<37;i++){
        gl[i]= newprices[i] - prices[i];
    }
}
            //portfolio screen
void Showport(string arr[][3],float prices[],float newprices[],float low[],float high[],float &balance,int stocks[],string &user,float &prevbalance,float gl[]){
    float totalgain=0;
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( h, 31);
    cout<<setw(53)<<"Portfolio owner:"<<user<<"(Live)"<<setw(28)<<" "<<endl;
    SetConsoleTextAttribute ( h, 14);
    cout<<"Show updates:"<<static_cast<char>(9166)<<" |";
    cout<<"Live Market:L";
    cout<<" |"<<"Add Stock:A"<<"|"<<"Remove Stock:R"<<"|"<<"Add money:M"<<"|"<<"WithDraw:W"<<endl;
    SetConsoleTextAttribute ( h, 240);
    cout<<"Stocks"<<setw(14)<<"Company Name"<<setw(16)<<"Shares"<<setw(9)<<"Current"<<setw(10)<<"Previous"<<setw(10)<<"Gain/Loss"<<"   "<<"High"<<"   "<<"Low"<<endl;
    for(int i=0;i<37;i++){
        if(stocks[i]!=0){
            totalgain = totalgain + (gl[i] * stocks[i]);
            cout<<arr[i+1][0];
            cals(arr[i+1][0],arr[i+1][1],1);
            cout<<arr[i+1][1]<<setw(7);
            cout<<stocks[i]<<setw(10)<<newprices[i]<<setw(8)<<prices[i];
            if((gl[i] * stocks[i])>0){
                SetConsoleTextAttribute ( h, 250);
                cout<<setw(8)<<"+"<<(gl[i] * stocks[i]);
                SetConsoleTextAttribute ( h, 240);
            }else if((gl[i] * stocks[i])<0){
                SetConsoleTextAttribute ( h, 252);
                cout<<setw(8)<<(gl[i] * stocks[i]);
                SetConsoleTextAttribute ( h, 240);
            }else{
                cout<<setw(8)<<(gl[i] * stocks[i]);
            }
            cout<<setw(8)<<high[i]<<setw(8)<<low[i]<<endl;
        }
    }
    if(totalgain>0){
        cout<<"Today's Gain or Loss (Rs.): ";
        SetConsoleTextAttribute ( h, 250);
        cout<<"+"<<totalgain<<endl;
        SetConsoleTextAttribute ( h, 240);
    }else if(totalgain<0){
        cout<<"Today's Gain or Loss (Rs.): ";
        SetConsoleTextAttribute ( h, 252);
        cout<<totalgain<<endl;
        SetConsoleTextAttribute ( h, 240);
    }else{
        cout<<"Today's Gain or Loss (Rs.): "<<totalgain<<endl;
    }
    cout<<"Previous Balance (Rs.): "<<prevbalance<<endl;
    cout<<"New Balance (Rs.): "<<balance<<endl;


}
        //writing portfolio
void writerport(string arr[][3],float prices[],float newprices[],float low[],float high[],float &balance,int stocks[],string &user,float &prevbalance,float gl[]){
    int counter=0;
    int totalgain=0;
    ofstream fout;
    fout.open("portfolio.txt");
    for(int i=0;i<117;i++)
        fout<<"*";
    fout<<endl;
    fout<<"Portfolio owner: "<<user;
    fout<<endl;
    fout<<"Stocks"<<setw(19)<<"Company Name"<<setw(24)<<"Shares"<<setw(12)<<"Close"<<setw(18)<<"Previous";
    fout<<setw(17)<<"Gain/Loss"<<setw(11)<<"High"<<setw(10)<<"Low"<<endl;
    for(int i=0;i<117;i++)
        fout<<"*";

    fout<<" "<<endl;
    for(int i=0;i<37;i++){
        if(stocks[i]!=0){
            totalgain = totalgain + (gl[i] * stocks[i]);
            fout<<arr[i+1][0];
        while(arr[i+1][0][counter]!='\0'){
            counter++;
        }

        for(int j=0;j<(13-counter);j++){
            fout<<" ";
        }
        counter=0;
            fout<<arr[i+1][1];

        while(arr[i+1][1][counter]!='\0'){
            counter++;
        }

        for(int k=0;k<(33-counter);k++){
            fout<<" ";
        }
        counter=0;

            fout<<fixed<<setprecision(2)<<stocks[i]<<setw(15)<<newprices[i]<<setw(15)<<prices[i];
            if((gl[i] * stocks[i])>0){
                fout<<fixed<<setprecision(2)<<setw(18)<<"+"<<(gl[i] * stocks[i]);
            }else if((gl[i] * stocks[i])<0){
                fout<<fixed<<setprecision(2)<<setw(17)<<(gl[i] * stocks[i]);
            }else{
                fout<<fixed<<setprecision(2)<<setw(17)<<(gl[i] * stocks[i]);
            }
            fout<<fixed<<setprecision(2)<<setw(12)<<high[i]<<setw(11)<<low[i]<<endl;
        }

    }
    for(int i=0;i<117;i++)
        fout<<"*";
    fout<<" "<<endl;
    if(totalgain>0)
        fout<<fixed<<setprecision(2)<<"Today's Gain or Loss (Rs.): +"<<totalgain<<endl;
    else
        fout<<fixed<<setprecision(2)<<"Today's Gain or Loss (Rs.): "<<totalgain<<endl;
    fout<<fixed<<setprecision(2)<<"Previous Balance (Rs.): "<<prevbalance<<endl;
    fout<<fixed<<setprecision(2)<<"New Balance (Rs.): "<<balance<<endl;
    for(int i=0;i<35;i++)
        fout<<"*";


    fout.close();

}
            //writing market
void writemarket(string arr[][3],float newprices[]){
    ofstream fout;
    fout.open("companies.txt");
    for(int i=0;i<38;i++){
        if(i==0){
            for(int j=0;j<3;j++){
                if(j<2)
                    fout<<arr[i][j]<<",";
                else
                    fout<<arr[i][j]<<endl;
            }
        }
        else{
            for(int j=0;j<2;j++){
                fout<<arr[i][j]<<",";
            }
            fout<<fixed<<setprecision(2)<<newprices[i-1]<<endl;
        }
    }
}
        //reading portfolio
void readport(string &user,float &prevbalance,float &balance,int stocks[],string arr[][3],float prices[],float newprices[]){
	int index=0;
	float p=0;
	char x;
	string str;
	ifstream fin;
	fin.open("portfolio.txt");
	getline(fin,str);
	getline(fin,str,':');
	getline(fin,user);
	getline(fin,str);
	getline(fin,str);
	getline(fin,str,' ');
	while(1){
		if(str[0]=='*'){
			break;
		}else{
			for(int i=0;i<38;i++){
				if(str==arr[i][0]){
					index=i;
				}
			}
			getline(fin,str,'.');
			fin>>p;
			stocks[index-1]=p;
			fin>>p;
			newprices[index-1]=p;
			fin>>p;
			prices[index-1]=p;
			p=0;
			getline(fin,str);
		}
	getline(fin,str,' ');
}
	getline(fin,str);
	getline(fin,str);
	getline(fin,str,':');
	fin.get(x);
	fin>>p;
	prevbalance=p;
	getline(fin,str,':');
	fin.get(x);
	fin>>p;
	balance=p;
}
            //top advancer
int top(float prices[],float low[]){
	float hi;
	int index=0;
	hi=(prices[0]-low[0])/prices[0];
	for(int i=1;i<37;i++){
		if((prices[i]-low[i])/prices[i]>hi)
			index=i;
	}
	return index;
}
        //Top decliner
int lowes(float prices[],float high[]){
	float lo;
	int index=0;
	lo=(high[0]-prices[0])/prices[0];
	for(int i=1;i<37;i++){
		if((high[i]-prices[i])/prices[i]>lo)
			index=i;

	}
	return index;
}


