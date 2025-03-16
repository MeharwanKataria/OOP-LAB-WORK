#include<iostream>
using namespace std;

class employee{
	protected:
		string id;
		string name;
	public:
		employee(string id, string name):id(id),name(name){}
		void display(){
			cout<<"ID name: "<<id<<endl;
			cout<<"Name: "<<name<<endl;
		}
};
class ordertaker:public employee{
	public:
		void takeorder(){
		cout<<"waiter is taking oreder"<<endl;}
};
class orderpreparer:public employee{
	public:
		void cook(){
			cout<<"Chef is cooking the order"<<endl;
		}
};
class cashier:public employee{
	public:
		void cashier(){
			cout<<"Cashier is billing the amount"<<endl;
		}
};
class menu
