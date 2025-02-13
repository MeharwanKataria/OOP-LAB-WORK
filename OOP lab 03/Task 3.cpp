#include<iostream>
#include<string>
#include<cstdio>

using namespace std;
class glass{
	public:
	int liquidlevel;
	glass(){
		liquidlevel=200;
	}
	void refill(){
		liquidlevel=200;
		cout<<"The glass has been refilled."<<endl;
	}
	void drink(int noamount){
		liquidlevel-=noamount;
		cout<<"You have drink "<<noamount<< "ml"<<endl;
		if(liquidlevel<100){
			refill();
		}
	}
};
int main(int argc,char*argv[]){
	glass waterglass;
	int wateramu;
	while(1){
		int choice;
	cout<<"current glass level: "<<waterglass.liquidlevel <<"ml"<<endl;
	cout<<"1.Drink\n2.Refill\n3.Exit"<<endl;
	cout<<"Please select the option"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"Enter the amount of water you want to drink."<<endl;
			cin>>wateramu;
			waterglass.drink(wateramu);
			break;
		case 2:
			waterglass.refill();
			break;
		case 3:
			cout<<"thankyou"<<endl;
			exit(1);
			break;
	}
}}
