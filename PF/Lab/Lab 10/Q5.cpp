#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	int icecream=0;
	int flavour=0;
	int top=0;
	int price=0;
	
	cout<<setw(15)<<"Menu"<<endl;
	do{
		cout<<"Ice Creame Type"<<endl;
		cout<<"1-Cone"<<endl;
		cout<<"2-Cup"<<endl;
		cout<<"0-Exit"<<endl;
		cin>>icecream;
			switch(icecream){
				case 1:
					do{
						cout<<"Flavour Type"<<endl;
						cout<<"1-chocolate"<<endl;
						cout<<"2-strawberry"<<endl;
						cout<<"3-mint chocolate"<<endl;
						cout<<"4-vanilla"<<endl;
						cout<<"5-cookie n cream"<<endl;
						cout<<"6-mango"<<endl;
						cout<<"0-Exit"<<endl;
						cin>>flavour;
							switch(flavour){
								case 1:
									do{
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										
										}while(top!=0);
										price = price + 40;
									break;
								case 2:
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										}while(top!=0);
										price = price + 50;
									break;
								case 3:
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										
										}while(top!=0);
										price = price + 60;
									break;
								case 4:
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										}while(top!=0);
										price = price + 40;
									break;
								case 5:
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										}while(top!=0);
										price = price + 60;
									break;

										break;
								case 0:
									break;
								default:
									cout<<"Invalid Input"<<endl;
									break;
							
							
							
							}
					}while(flavour!=0);
					price=price + 10;
					break;
				case 2:
					do{
						cout<<"Flavour Type"<<endl;
						cout<<"1-chocolate"<<endl;
						cout<<"2-strawberry"<<endl;
						cout<<"3-mint chocolate"<<endl;
						cout<<"4-vanilla"<<endl;
						cout<<"5-cookie n cream"<<endl;
						cout<<"6-mango"<<endl;
						cout<<"0-Exit"<<endl;
						cin>>flavour;
							switch(flavour){
								case 1:
									do{
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										
										}while(top!=0);
										price = price + 40;
									break;
								case 2:
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										}while(top!=0);
										price = price + 50;
									break;
								case 3:
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										
										}while(top!=0);
										price = price + 60;
									break;
								case 4:
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										}while(top!=0);
										price = price + 40;
									break;
								case 5:
										cout<<"Flavour Type"<<endl;
										cout<<"1-sprinkles"<<endl;
										cout<<"2-chocolate chips"<<endl;
										cout<<"3-chocolate syrup"<<endl;
										cout<<"4-nuts"<<endl;
										cout<<"5-M&Ms"<<endl;
										cout<<"0-Exit"<<endl;
										cin>>top;
											switch(top){
												case 1:
													price=price+10;
													break;
												case 2:
													price=price+15;
													break;
												case 3:
													price=price+15;
													break;
												case 4:
													price=price+20;
													break;
												case 5:
													price=price+20;
													break;
												case 0:
													break;
												default:
													cout<<"Invalid Input"<<endl;
													break;
											}
										}while(top!=0);
										price = price + 60;
									break;

										break;
								case 0:
									break;
								default:
									cout<<"Invalid Input"<<endl;
									break;
							
							
							
							}
					}while(flavour!=0);
					price=price + 10;
					break;

				
				price=price + 20;
					break;
				case 0:
					break;
				default:
					cout<<"Invalid Input"<<endl;
					break;
			}
	}while(icecream!=0);
	
	
	cout<<"Price:"<<price<<endl;
	return 0;
}
