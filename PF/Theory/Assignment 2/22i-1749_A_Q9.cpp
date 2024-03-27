/*
Name : Mirza Humayun Masood.
Roll No : I22-1749
Class : BSCY(A)
*/
#include <iostream>
#include <ctime>

using namespace std;

int main(){

    srand(time(0));
    const int IK = 1000;
    const int JM = 1000;
    const int JA = 1000;
    const int AM = 1000;
    const int ST = 3000;
    const int SA = 3000;
    const int IB = 2500;
    const int YA = 2500;
    //remaining

    int ik_r= rand() % 1000;
    int jm_r= rand() % 1000;
    int ja_r= rand() % 1000;
    int am_r= rand() % 1000;
    int st_r= rand() % 3000;
    int sa_r= rand() % 3000;
    int ib_r= rand() % 2500;
    int ya_r= rand() % 2500;


    int choice,choice2,choice3,adults,childs;
    int price;
    double CNIC1,CNIC2,CNIC3,CNIC4,CNIC5;
    char pew;


    cout<<"Enter Choice :"<<endl<<endl;
    cout<<"1. 27 Feb 2020 – Islamabad United v Quetta Gladiators, Pindi Cricket Stadium"<<endl<<"(7pm-10.15pm)"<<endl<<endl;
    cout<<"2. 28 Feb 2020 – Peshawar Zalmi v Lahore Qalandars, Pindi Cricket Stadium"<<endl<<"(8pm-11.15pm)"<<endl<<endl;
    cout<<"3. 29 Feb 2020 – Islamabad United v Peshawar Zalmi, Pindi Cricket Stadium"<<endl<<"(7pm-10.15pm)"<<endl<<endl;
    cout<<"4. 1 Mar 2020 – Islamabad United v Karachi Kings, Pindi Cricket Stadium"<<endl<<"(7pm-10.15pm)"<<endl<<endl;
    cout<<"5. 2 Mar 2020 – Peshawar Zalmi v Karachi Kings, Pindi Cricket Stadium"<<endl<<"(7pm-10.15pm)"<<endl<<endl;
    cout<<"6. 5 Mar 2020 – Peshawar Zalmi v Quetta Gladiators, Pindi Cricket Stadium"<<endl<<"(7pm-10.15pm)"<<endl<<endl;
    cout<<"7. 7 Mar 2020 – Peshawar Zalmi v Islamabad United, Pindi Cricket Stadium"<<endl<<"(2pm-5.15pm)"<<endl<<endl;
    cout<<"8. 8 Mar 2020 – Multan Sultans v Islamabad United, Pindi Cricket Stadium"<<endl<<"(2pm-5.15pm)"<<endl<<endl;
    cout<<"Choice: ";
    cin>>choice;
    cout<<"***************************************************************************"<<endl<<endl;

    switch(choice){
        case 1:
        	cout<<"Choose Enclosure:"<<endl<<endl;
        	cout<<"1-Imran Khan enclosure,\t \t Remaing Seats: "<< (IK - ik_r)<<endl<<endl;
        	cout<<"2-Javed Miandad enclosure,\t Remaing Seats: "<<(JM - jm_r)<<endl<<endl;
        	cout<<"3-Javed Akhter enclosure,\t Remaing Seats: "<<(JA - ja_r)<<endl<<endl;
        	cout<<"4-Azhar Mehmood enclosure,\t Remaing Seats: "<<(AM - am_r)<<endl<<endl;
        	cout<<"5-Sohail Tanveer enclosure,\t Remaing Seats: "<<(ST - st_r)<<endl<<endl;
        	cout<<"6-Shoaib Akhtar enclosure,\t Remaing Seats: "<<(SA - sa_r)<<endl<<endl;
        	cout<<"7-Imran Buksh enclosure,\t Remaing Seats: "<<(IB - ib_r)<<endl<<endl;
        	cout<<"8-Yasir Arafat enclosure,\t Remaing Seats: "<<(YA - ya_r)<<endl<<endl;
        	cin>>choice2;
        		switch(choice2){
        			case 1:
        				cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 2:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 3:
        			cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 4:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 5:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 6:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 7:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 8:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;


        			default:
        			    cout<<"Invalid Input"<<endl;



        		}

			break;
		case 2:
		    cout<<"Choose Enclosure:"<<endl<<endl;
        	cout<<"1-Imran Khan enclosure,\t \t Remaing Seats: "<< (IK - ik_r)<<endl<<endl;
        	cout<<"2-Javed Miandad enclosure,\t Remaing Seats: "<<(JM - jm_r)<<endl<<endl;
        	cout<<"3-Javed Akhter enclosure,\t Remaing Seats: "<<(JA - ja_r)<<endl<<endl;
        	cout<<"4-Azhar Mehmood enclosure,\t Remaing Seats: "<<(AM - am_r)<<endl<<endl;
        	cout<<"5-Sohail Tanveer enclosure,\t Remaing Seats: "<<(ST - st_r)<<endl<<endl;
        	cout<<"6-Shoaib Akhtar enclosure,\t Remaing Seats: "<<(SA - sa_r)<<endl<<endl;
        	cout<<"7-Imran Buksh enclosure,\t Remaing Seats: "<<(IB - ib_r)<<endl<<endl;
        	cout<<"8-Yasir Arafat enclosure,\t Remaing Seats: "<<(YA - ya_r)<<endl<<endl;
        	cin>>choice2;
        		switch(choice2){
        			case 1:
        				cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 2:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 3:
        			cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 4:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 5:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 6:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 7:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 8:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;


        			default:
        			    cout<<"Invalid Input"<<endl;



        		}

			break;
		case 3:
		    cout<<"Choose Enclosure:"<<endl<<endl;
        	cout<<"1-Imran Khan enclosure,\t \t Remaing Seats: "<< (IK - ik_r)<<endl<<endl;
        	cout<<"2-Javed Miandad enclosure,\t Remaing Seats: "<<(JM - jm_r)<<endl<<endl;
        	cout<<"3-Javed Akhter enclosure,\t Remaing Seats: "<<(JA - ja_r)<<endl<<endl;
        	cout<<"4-Azhar Mehmood enclosure,\t Remaing Seats: "<<(AM - am_r)<<endl<<endl;
        	cout<<"5-Sohail Tanveer enclosure,\t Remaing Seats: "<<(ST - st_r)<<endl<<endl;
        	cout<<"6-Shoaib Akhtar enclosure,\t Remaing Seats: "<<(SA - sa_r)<<endl<<endl;
        	cout<<"7-Imran Buksh enclosure,\t Remaing Seats: "<<(IB - ib_r)<<endl<<endl;
        	cout<<"8-Yasir Arafat enclosure,\t Remaing Seats: "<<(YA - ya_r)<<endl<<endl;
        	cin>>choice2;
        		switch(choice2){
        			case 1:
        				cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 2:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 3:
        			cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 4:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 5:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 6:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 7:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 8:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 2700) + (childs * 2400);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 3000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*2700);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*3000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;


        			default:
        			    cout<<"Invalid Input"<<endl;



        		}

			break;
		case 4:
		     cout<<"Choose Enclosure:"<<endl<<endl;
        	cout<<"1-Imran Khan enclosure,\t \t Remaing Seats: "<< (IK - ik_r)<<endl<<endl;
        	cout<<"2-Javed Miandad enclosure,\t Remaing Seats: "<<(JM - jm_r)<<endl<<endl;
        	cout<<"3-Javed Akhter enclosure,\t Remaing Seats: "<<(JA - ja_r)<<endl<<endl;
        	cout<<"4-Azhar Mehmood enclosure,\t Remaing Seats: "<<(AM - am_r)<<endl<<endl;
        	cout<<"5-Sohail Tanveer enclosure,\t Remaing Seats: "<<(ST - st_r)<<endl<<endl;
        	cout<<"6-Shoaib Akhtar enclosure,\t Remaing Seats: "<<(SA - sa_r)<<endl<<endl;
        	cout<<"7-Imran Buksh enclosure,\t Remaing Seats: "<<(IB - ib_r)<<endl<<endl;
        	cout<<"8-Yasir Arafat enclosure,\t Remaing Seats: "<<(YA - ya_r)<<endl<<endl;
        	cin>>choice2;
        		switch(choice2){
        			case 1:
        				cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 2:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 3:
        			cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 4:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 5:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 6:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 7:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 8:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;


        			default:
        			    cout<<"Invalid Input"<<endl;



        		}

			break;
		case 5:
 cout<<"Choose Enclosure:"<<endl<<endl;
        	cout<<"1-Imran Khan enclosure,\t \t Remaing Seats: "<< (IK - ik_r)<<endl<<endl;
        	cout<<"2-Javed Miandad enclosure,\t Remaing Seats: "<<(JM - jm_r)<<endl<<endl;
        	cout<<"3-Javed Akhter enclosure,\t Remaing Seats: "<<(JA - ja_r)<<endl<<endl;
        	cout<<"4-Azhar Mehmood enclosure,\t Remaing Seats: "<<(AM - am_r)<<endl<<endl;
        	cout<<"5-Sohail Tanveer enclosure,\t Remaing Seats: "<<(ST - st_r)<<endl<<endl;
        	cout<<"6-Shoaib Akhtar enclosure,\t Remaing Seats: "<<(SA - sa_r)<<endl<<endl;
        	cout<<"7-Imran Buksh enclosure,\t Remaing Seats: "<<(IB - ib_r)<<endl<<endl;
        	cout<<"8-Yasir Arafat enclosure,\t Remaing Seats: "<<(YA - ya_r)<<endl<<endl;
        	cin>>choice2;
        		switch(choice2){
        			case 1:
        				cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 2:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 3:
        			cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 4:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 5:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 6:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 7:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 8:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;


        			default:
        			    cout<<"Invalid Input"<<endl;



        		}

			break;
		case 6:
 cout<<"Choose Enclosure:"<<endl<<endl;
        	cout<<"1-Imran Khan enclosure,\t \t Remaing Seats: "<< (IK - ik_r)<<endl<<endl;
        	cout<<"2-Javed Miandad enclosure,\t Remaing Seats: "<<(JM - jm_r)<<endl<<endl;
        	cout<<"3-Javed Akhter enclosure,\t Remaing Seats: "<<(JA - ja_r)<<endl<<endl;
        	cout<<"4-Azhar Mehmood enclosure,\t Remaing Seats: "<<(AM - am_r)<<endl<<endl;
        	cout<<"5-Sohail Tanveer enclosure,\t Remaing Seats: "<<(ST - st_r)<<endl<<endl;
        	cout<<"6-Shoaib Akhtar enclosure,\t Remaing Seats: "<<(SA - sa_r)<<endl<<endl;
        	cout<<"7-Imran Buksh enclosure,\t Remaing Seats: "<<(IB - ib_r)<<endl<<endl;
        	cout<<"8-Yasir Arafat enclosure,\t Remaing Seats: "<<(YA - ya_r)<<endl<<endl;
        	cin>>choice2;
        		switch(choice2){
        			case 1:
        				cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 2:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 3:
        			cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 4:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 5:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 6:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 7:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 8:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;


        			default:
        			    cout<<"Invalid Input"<<endl;



        		}

			break;
		case 7:
		     cout<<"Choose Enclosure:"<<endl<<endl;
        	cout<<"1-Imran Khan enclosure,\t \t Remaing Seats: "<< (IK - ik_r)<<endl<<endl;
        	cout<<"2-Javed Miandad enclosure,\t Remaing Seats: "<<(JM - jm_r)<<endl<<endl;
        	cout<<"3-Javed Akhter enclosure,\t Remaing Seats: "<<(JA - ja_r)<<endl<<endl;
        	cout<<"4-Azhar Mehmood enclosure,\t Remaing Seats: "<<(AM - am_r)<<endl<<endl;
        	cout<<"5-Sohail Tanveer enclosure,\t Remaing Seats: "<<(ST - st_r)<<endl<<endl;
        	cout<<"6-Shoaib Akhtar enclosure,\t Remaing Seats: "<<(SA - sa_r)<<endl<<endl;
        	cout<<"7-Imran Buksh enclosure,\t Remaing Seats: "<<(IB - ib_r)<<endl<<endl;
        	cout<<"8-Yasir Arafat enclosure,\t Remaing Seats: "<<(YA - ya_r)<<endl<<endl;
        	cin>>choice2;
        		switch(choice2){
        			case 1:
        				cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 2:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 3:
        			cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 4:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 5:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 6:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 7:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 8:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1800) + (childs * 1600);
        												break;
        											case 2:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 3:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 4:
        												price = (adults * 450) + (childs * 400);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 2000"<<endl;
        									cout<<"2-Premium – Rs. 1500"<<endl;
        									cout<<"3-First-class – Rs. 1000"<<endl;
        									cout<<"4-General – Rs. 500"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1800);
        													break;
        												case 2:
        													price = (adults*1350);
        													break;
        												case 3:
        													price = (adults*900);
        													break;
        												case 4:
        													price = (adults*450);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*2000);
        													break;
        												case 2:
        													price = (adults*1500);
        													break;
        												case 3:
        													price = (adults*1000);
        													break;
        												case 4:
        													price = (adults*500);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;


        			default:
        			    cout<<"Invalid Input"<<endl;



        		}

			break;
				case 8:
		     cout<<"Choose Enclosure:"<<endl<<endl;
        	cout<<"1-Imran Khan enclosure,\t \t Remaing Seats: "<< (IK - ik_r)<<endl<<endl;
        	cout<<"2-Javed Miandad enclosure,\t Remaing Seats: "<<(JM - jm_r)<<endl<<endl;
        	cout<<"3-Javed Akhter enclosure,\t Remaing Seats: "<<(JA - ja_r)<<endl<<endl;
        	cout<<"4-Azhar Mehmood enclosure,\t Remaing Seats: "<<(AM - am_r)<<endl<<endl;
        	cout<<"5-Sohail Tanveer enclosure,\t Remaing Seats: "<<(ST - st_r)<<endl<<endl;
        	cout<<"6-Shoaib Akhtar enclosure,\t Remaing Seats: "<<(SA - sa_r)<<endl<<endl;
        	cout<<"7-Imran Buksh enclosure,\t Remaing Seats: "<<(IB - ib_r)<<endl<<endl;
        	cout<<"8-Yasir Arafat enclosure,\t Remaing Seats: "<<(YA - ya_r)<<endl<<endl;
        	cin>>choice2;
        		switch(choice2){
        			case 1:
        				cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 2:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 3:
        			cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 4:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 5:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 6:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 7:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;
        			case 8:
        			    cout<<"Do You want to buy Tickets for Family? (y/n): ";
        				cin>>pew;
        					switch(pew){
        						case 'y':
        							cout<<"How many Adults in your family are: ";
        							cin>>adults;
        							cout<<"How many Children in your family are: ";
        							cin>>childs;
        								if(childs==0 || childs<0){
        									cout<<"Invalid input"<<endl;
        							}
        								else if(adults<=4 && childs<=5){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
	        								cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										switch(choice3){
        											case 1:
        												price = (adults * 1350) + (childs * 1200);
        												break;
        											case 2:
        												price = (adults * 900) + (childs * 800);
        												break;
        											case 3:
        												price = (adults * 450) + (childs * 400);
        												break;
        											case 4:
        												price = (adults * 225) + (childs * 200);
        												break;
        											default:
        												cout<<"Invalid Input"<<endl;
        												break;
        										}
        							}else{
        								cout<<"Invalid Input"<<endl;
        							}
        							break;

        						case 'n':
        							cout<<"How Many Adults you are: ";
        							cin>>adults;
        								if(adults<=8){
        									cout<<"Enter CNIC of one person: ";
        									cin>>CNIC1;
        									cout<<endl;
        									cout<<"Which Ticket you want to buy:"<<endl;
        									cout<<"1-VIP – Rs. 1500"<<endl;
        									cout<<"2-Premium – Rs. 1000"<<endl;
        									cout<<"3-First-class – Rs. 500"<<endl;
        									cout<<"4-General – Rs. 250"<<endl;
        									cout<<"Enter Choice: ";
        									cin>>choice3;
        										if(adults>4){
        											switch(choice3){
        												case 1:
        													price = (adults*1350);
        													break;
        												case 2:
        													price = (adults*900);
        													break;
        												case 3:
        													price = (adults*450);
        													break;
        												case 4:
        													price = (adults*225);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}


        										}else{

        										switch(choice3){
        												case 1:
        													price = (adults*1500);
        													break;
        												case 2:
        													price = (adults*1000);
        													break;
        												case 3:
        													price = (adults*500);
        													break;
        												case 4:
        													price = (adults*250);
        													break;

        												default:
        													cout<<"Invalid Input"<<endl;
        											}

        										}



        							}else{
        								cout<<"Invalid Input"<<endl;
        							}


        							break;


        					}
        				break;


        			default:
        			    cout<<"Invalid Input"<<endl;



        		}

			break;

		default:
		    cout<<"Invalid Input"<<endl;







    }

    cout<<"Your Total Price is : " <<price<<endl;




return 0;
}

