/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include <iostream>

using namespace std;

int main(){

    char item;
    int type,n,p,price;
    char num;
    cout<<"Items: "<<endl;
    cout<<"B = Burger"<<endl;
    cout<<"F = French Fries"<<endl;
    cout<<"P = Pizza"<<endl;
    cout<<"S = Sandwiches"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>item;

    cout<<endl<<endl;

    switch(item){
        case 'B':
            cout<<"Burger 1 Rs. 200 = 1"<<endl;
            cout<<"Burger 2 Rs. 250 = 2"<<endl;
            cout<<"Burger 3 Rs. 300 = 3"<<endl;
            cout<<"Burger 4 Rs. 350 = 4"<<endl;
            cout<<"Enter Your Choice: ";
            cin>>type;
            cout<<endl<<endl;
                switch(type){
                    case 1:
                        p=200;
                        cout<<"For 1 Burger = A"<<endl;
                        cout<<"For 2 Burgers = B"<<endl;
                        cout<<"For 4 Burgers = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 2:
                        p=250;
                        cout<<"For 1 Burger = A"<<endl;
                        cout<<"For 2 Burgers = B"<<endl;
                        cout<<"For 4 Burgers = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 3:
                        p=300;
                        cout<<"For 1 Burger = A"<<endl;
                        cout<<"For 2 Burgers = B"<<endl;
                        cout<<"For 4 Burgers = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 4:
                        p=350;
                        cout<<"For 1 Burger = A"<<endl;
                        cout<<"For 2 Burgers = B"<<endl;
                        cout<<"For 4 Burgers = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    default:
                        cout<<"Invalid Input"<<endl;
                        break;
                }
            break;

        case 'F':
            cout<<"French Fries (SHORT) Rs. 50 = 1"<<endl;
            cout<<"French Fries (MEDIUM) Rs. 100 = 2"<<endl;
            cout<<"French Fries (LARGE) Rs. 150 = 3"<<endl;
            cout<<"French Fries (EXTRA LARGE) Rs. 200 = 4"<<endl;
            cout<<"Enter Your Choice: ";
            cin>>type;
            cout<<endl<<endl;
                switch(type){
                    case 1:
                        p=50;
                        cout<<"For 1 Pack = A"<<endl;
                        cout<<"For 2 Packs = B"<<endl;
                        cout<<"For 4 Packs = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 2:
                        p=100;
                        cout<<"For 1 Pack = A"<<endl;
                        cout<<"For 2 Packs = B"<<endl;
                        cout<<"For 4 Packs = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 3:
                        p=150;
                        cout<<"For 1 Pack = A"<<endl;
                        cout<<"For 2 Packs = B"<<endl;
                        cout<<"For 4 Packs = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 4:
                        p=200;
                        cout<<"For 1 Pack = A"<<endl;
                        cout<<"For 2 Packs = B"<<endl;
                        cout<<"For 4 Packs = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    default:
                        cout<<"Invalid Input"<<endl;
                        break;
                }
            break;
        case 'P':
            cout<<"Pizza (SHORT) Rs. 350 = 1"<<endl;
            cout<<"Pizza (MEDIUM) Rs. 700 = 2"<<endl;
            cout<<"Pizza (LARGE) Rs. 1100 = 3"<<endl;
            cout<<"Pizza (EXTRA LARGE) Rs. 1500 = 4"<<endl;
            cout<<"Enter Your Choice: ";
            cin>>type;
            cout<<endl<<endl;
                switch(type){
                    case 1:
                        p=350;
                        cout<<"For 1 Pizza = A"<<endl;
                        cout<<"For 2 Pizzas = B"<<endl;
                        cout<<"For 4 Pizzas = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 2:
                        p=700;
                        cout<<"For 1 Pizza = A"<<endl;
                        cout<<"For 2 Pizzas = B"<<endl;
                        cout<<"For 4 Pizzas = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 3:
                        p=1100;
                        cout<<"For 1 Pizza = A"<<endl;
                        cout<<"For 2 Pizzas = B"<<endl;
                        cout<<"For 4 Pizzas = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 4:
                        p=1500;
                        cout<<"For 1 Pizza = A"<<endl;
                        cout<<"For 2 Pizzas = B"<<endl;
                        cout<<"For 4 Pizzas = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    default:
                        cout<<"Invalid Input"<<endl;
                        break;
                }
            break;
        case 'S':
            cout<<"Sandwich 1 Rs. 120 = 1"<<endl;
            cout<<"Sandwich 2 Rs. 150 = 2"<<endl;
            cout<<"Sandwich 3 Rs. 180 = 3"<<endl;
            cout<<"Sandwich 4 Rs. 200 = 4"<<endl;
            cout<<"Enter Your Choice: ";
            cin>>type;
            cout<<endl<<endl;
                switch(type){
                    case 1:
                        p=120;
                        cout<<"For 1 Sandwich = A"<<endl;
                        cout<<"For 2 Sandwichs = B"<<endl;
                        cout<<"For 4 Sandwichs = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 2:
                        p=150;
                        cout<<"For 1 Sandwich = A"<<endl;
                        cout<<"For 2 Sandwichs = B"<<endl;
                        cout<<"For 4 Sandwichs = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 3:
                        p=180;
                        cout<<"For 1 Sandwich = A"<<endl;
                        cout<<"For 2 Sandwichs = B"<<endl;
                        cout<<"For 4 Sandwichs = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    case 4:
                        p=200;
                        cout<<"For 1 Sandwich = A"<<endl;
                        cout<<"For 2 Sandwichs = B"<<endl;
                        cout<<"For 4 Sandwichs = C"<<endl;
                        cout<<"Enter Your Choice: ";
                        cin>>num;
                        cout<<endl<<endl;
                            switch(num){
                                case 'A':
                                    n=1;
                                    price = p*n;
                                    break;
                                case 'B':
                                    n=2;
                                    price = p*n;
                                    break;
                                case 'C':
                                    n=4;
                                    price = p*n;
                                    break;
                                default:
                                    cout<<"Invalid Input"<<endl;
                                    break;
                            }
                        break;
                    default:
                        cout<<"Invalid Input"<<endl;
                        break;
                }
            break;
        default:
            cout<<"Invalid Input"<<endl;
            break;

    }


    switch(price){
        case 0:
            break;
        default:
            cout<<"Your Total Price is: "<<price<<endl;
            break;
    }









return 0;
}
