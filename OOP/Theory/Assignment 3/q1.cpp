/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
string zellerdays(int d,int m,int y){       //function to calculate which day of the week is going
    if(m == 1) {
        m = 13;
        y--;
    }
    if(m == 2) {
        m = 14;
        y--;
    }
    int k = y % 100;
    int j = y / 100;
    int h = d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    switch (h) {
    case 0:
        return "Saturday";
        break;
    case 1:
        return "Sunday";
        break;
    case 2:
        return "Monday";
        break;
    case 3:
        return "Tuesday";
        break;
    case 4:
        return "Wednesday";
        break;
    case 5:
        return "Thursday";
        break;
    case 6:
        return "Friday";
        break;
    }
}
string monthret(int x){     //returns the name of month
    string arr[12] = {"January", "February", "March", "April", "May", "June", "July","August", "September", "October", "November","December"};
    return arr[x-1];
}
int zeller(int day,int month,int year){             //it helps with the day of week aswell
    int days[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    if(month<3)
        year--;
    int x = (year + year/4 - year/100 + year/400 + days[month-1] + day) % 7;
    return x;
}
int numdays(int m,int y){
    int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(m == 2){
        if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            return 29;
        else
            return 28;
    }else{
        return arr[m-1];
    }
}
class Calender{         //Calender class
private:            //private data members
    int year;
    int month;
public:
    Calender(int m,int y){      //cnstrct
        this->year = y;
        this->month = m;
    }
    void setm(int x){           //setters
        this->month = x;
    }
    void sety(int x){
        this->year = x;
    }
    void Display(){             //display calender
        int days = numdays(this->month,this->year);
        int x = zeller(1,this->month,this->year);
        int i;
        cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
        cout<<"    ";
        for(i = 0;i<x;i++){
            cout<<"     ";
        }
        for(int j=1;j<=days;j++){
            cout<<j<<setw(5);
            i++;
            if(i > 6){
                i=0;
                cout<<endl;
            }
        }
        cout<<endl;
    }
};
class Date{             //Date class
private:
    int day;
    int month;
    int year;
public:
    Date(int d,int m,int y){        //cnstrctr
        this->day = d;
        this->month = m;
        this->year = y;
    }
    void print(){               //print
        cout<<this->day<<" / "<<this->month<<" / "<<this->year<<endl;
    }
    void setd(int x){           //setters
        this->day = x;
    }
    void setm(int x){
        this->month = x;
    }
    void sety(int x){
        this->year = x;
    }
    int getd(){             //getters
        return this->day;
    }
    int getm(){
        return this->month;
    }
    int gety(){
        return this->year;
    }
    int operator-(Date& date2){         //calculting difference between two dates in an int
        long int total1 = this->year*365 + this->day;
        for(int i=1; i<this->month;i++){
            total1 = total1 + numdays(i,1);
        }
        int temp1 = this->year;
        int c=0;
        if(this->month <= 2){
            temp1--;
        }
        for(int i=0;i<= temp1;i++){
            if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)){
               c++;
            }
        }
        total1 = total1 + c;
        c=0;
        temp1 = date2.year;
        if(date2.month <= 2){
            temp1--;
        }
        for(int i=0;i<=temp1;i++){
            if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)){
               c++;
            }
        }


        long int total2 = date2.year*365 + date2.day;
        for(int i=0; i<date2.month;i++){
            total2 = total2 + numdays(i,1);
        }
        total2 = total2 + c;

        if(total1 > total2)
            return total1-total2;
        else
            return total2-total1;
    }
    Date futuredate(char* given){               //calculate the future date
        char *token = strtok(given," ");
        int num = atoi(token);
        //cout<<num<<endl;
        token = strtok(NULL,"\0");
        int i=0;

        if(token[0] == 'w'){
            num = num * 7;
        }else if(token[0] == 'm'){
            num = num * 30;
        }else if(token[0] == 'y'){
            num = num * 365;
        }
        int d = num;
        d = d + this->day;
        int m = this->month;
        int y = this->year;
        while(d > numdays(m,y)){
            d = d - numdays(m,y);
            m++;
            if(m>12){
                m=1;
                y++;
            }
        }
        return Date(d,m,y);

    }
    Date pastdate(char* given){         //calculate the past date
        char *token = strtok(given," ");
        int num = atoi(token);
        //cout<<num<<endl;
        token = strtok(NULL,"\0");
        int i=0;

        if(token[0] == 'w'){
            num = num * 7;
        }else if(token[0] == 'm'){
            num = num * 30;
        }else if(token[0] == 'y'){
            num = num * 365;
        }
        int d = this->day;
        d = d - num;
        int m = this->month;
        int y = this->year;
        while(d < 1){
            m--;
            if(m<1){
                m = 12;
                y--;
            }
            //cout<<m;
            d = d + numdays(m,y);
        }
        return Date(d,m,y);
    }
};

int main(){             //main
    time_t now = time(0);           //doin this to know whicch mnth is currently goin
    tm* localtm = localtime(&now);
    int year = 1900 + localtm->tm_year;
    int mnth = 1 + localtm->tm_mon;
    Calender A(mnth,year);      //makin calender
    A.Display();
    int x=0;
    int m=0;
    int y=0;
    int q=0,w=0,e=0;
    int dd=0;
    int weeks=0;
    int p=1;
    char *given = new char[100];            //a char array for inputs
    Date D1(0,0,0);
    Date D2(0,0,0);
    Date D3(0,0,0);
    do{
        cout<<"\nEnter Your Choice"<<endl;          //Do while loop for options
        cout<<"1 - Display calendar for a different month"<<endl;
        cout<<"2 - Calculate difference between two dates"<<endl;
        cout<<"3 - Calculate a future date"<<endl;
        cout<<"4 - Calculate a past date"<<endl;
        cout<<"5 - Exit"<<endl;
        cout<<"Choice : ";
        cin>>x;
        while(x<=0 || x>5){
            cout<<"Invalid Input, Enter again"<<endl;
            cin>>x;
        }
        switch(x){          //switch
            case 1:
                cout<<"Enter Month: ";
                cin>>m;
                while(m<=0 || m>12){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>m;
                }
                cout<<"Enter Year: ";
                cin>>y;
                while(y<=0){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>y;
                }
                A.setm(m);
                A.sety(y);
                A.Display();
            break;
            case 2:             //calculatin differences between dates
                cout<<"Enter The Day of First Date: ";
                cin>>q;
                while(q<=0 ||q>31){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>q;
                }
                cout<<"Enter The Month of First Date: ";
                cin>>w;
                while(w<=0 ||w>12){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>w;
                }
                cout<<"Enter The Year of First Date: ";
                cin>>e;
                while(e<=0){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>e;
                }
                D1.setd(q);
                D1.setm(w);
                D1.sety(e);
                cout<<"\n\nEnter The Day of Second Date: ";
                cin>>q;
                while(q<=0 ||q>31){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>q;
                }
                cout<<"Enter The Month of Second Date: ";
                cin>>w;
                while(w<=0 ||w>12){
                    cout<<"Invalid Input, Second again"<<endl;
                    cin>>w;
                }
                cout<<"Enter The Year of First Date: ";
                cin>>e;
                while(e<=0){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>e;
                }
                D2.setd(q);
                D2.setm(w);
                D2.sety(e);
                dd=D1-D2;
                weeks = dd/7;
                dd = dd%7;
                cout<<weeks<<" Weeks, "<<dd<<" Days.\n";

            break;
            case 3:             //future date
                cout<<"Enter The Day of Starting Date: ";
                cin>>q;
                while(q<=0 ||q>31){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>q;
                }
                cout<<"Enter The Month of Starting Date: ";
                cin>>w;
                while(w<=0 ||w>12){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>w;
                }
                cout<<"Enter The Year of Starting Date: ";
                cin>>e;
                while(e<=0){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>e;
                }
                D1.setd(q);
                D1.setm(w);
                D1.sety(e);
                delete []given;
                given = new char[100];
                cout<<"Enter The Input like (5 weeks, 7 Months) :";
                cin.ignore();
                cin.get(given,100);
                cout<<given;
                D3 = D1.futuredate(given);
                cout<<" from the start date ";
                cout<<D1.getd()<<" ";
                cout<<monthret(D1.getm());
                cout<<" "<<D1.gety();
                cout<<" is "<<zellerdays(D3.getd(),D3.getm(),D3.gety());
                cout<<", ";
                cout<<D3.getd()<<" "<<monthret(D3.getm())<<" "<<D3.gety()<<".";
            break;
            case 4:             //prev day
                cout<<"Enter The Day of Starting Date: ";
                cin>>q;
                while(q<=0 ||q>31){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>q;
                }
                cout<<"Enter The Month of Starting Date: ";
                cin>>w;
                while(w<=0 ||w>12){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>w;
                }
                cout<<"Enter The Year of Starting Date: ";
                cin>>e;
                while(e<=0){
                    cout<<"Invalid Input, Enter again"<<endl;
                    cin>>e;
                }
                D1.setd(q);
                D1.setm(w);
                D1.sety(e);
                delete []given;
                given = new char[100];
                cout<<"Enter The Input like (5 weeks, 7 Months) :";
                cin.ignore();
                cin.get(given,100);
                cout<<given;
                D3 = D1.pastdate(given);
                cout<<" from the start date ";
                cout<<D1.getd()<<" ";
                cout<<monthret(D1.getm());
                cout<<" "<<D1.gety();
                cout<<" is "<<zellerdays(D3.getd(),D3.getm(),D3.gety());
                cout<<", ";
                cout<<D3.getd()<<" "<<monthret(D3.getm())<<" "<<D3.gety()<<".";
            break;
            case 5:
                p=0;
            break;
        }
    }while(p);
    delete []given;



return 0;
}
