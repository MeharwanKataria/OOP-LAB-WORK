#include<iostream>
using namespace std;

class bankaccount{
	protected:
		string accountno;
		double balance;
	public:
		bankaccount(string accountno,double balance=0){
			this->accountno=accountno;
			this->balance=balance;
		}
		string getaccount(){
			return accountno;
		}
		double getbalance(){
			return balance;
		}
		void withdraw(double amount){
			balance-=amount;
			cout<<"Amount withdraw successfully"<<amount<<endl;
			cout<<"New balance: "<<balance<<endl;
		}
		void deposit(double amount){
			balance+=amount;
			cout<<"Amount deposit successfully"<<amount<<endl;
			cout<<"New balance: "<<balance<<endl;
		}
		
};
class savingaccount: public bankaccount{
	 private:
	 float monthlyinterest;
	 public:
	 savingaccount(string accountno,double balance,float mi):bankaccount(accountno,balance),monthlyinterest(mi){}
	 void apply(){
	 	balance+=balance*(monthlyinterest/100);
	 }
};
class overdraft:public bankaccount{
	private:
		float overdraftlimit;
	public:
		overdraft(string accountno,double balance,float od): bankaccount(accountno,balance),overdraftlimit(od){}
		void checkoverdraftlimit(float num){
			if(num>overdraftlimit){
				cout<<"You exceed the overdraft limit"<<endl;
			}
			else{
				balance-=num;
			}
		}
};
class businessaccount: public bankaccount{
	private:
		float tax;
	public:
		businessaccount(string accountno, double balance, float rate):bankaccount(accountno,balance),tax(rate){}
		void applytax(){
			balance=balance-balance*(tax/100);
			cout<<"New balance after applying tax"<<balance<<endl;
		}
};
class employee{
	protected:
		string name;
		string id;
	public:
		employee(string name,string id){
			this->name=name;
			this->id=id;
		}
		void display(){
			cout<<"Employee name: "<<name<<endl;
			cout<<"Id name: "<<id<<endl;
		}
};
class customer: public employee{
	private:
		bankaccount *account;
	public:
	customer(string name,string id,bankaccount *account):employee(name,id),account(account){}
	void deposit(double amount){
		account->deposit(amount);
	}		
	void withdraw(double amount){
		account->withdraw(amount);
	}
};
class teller:public employee{
	private:
		bankaccount *account;
	public:
		teller(string name,string id,bankaccount* account):employee(name,id),account(account){}
		void withdraw(double amount){
			account->withdraw(amount);
		}
		void deposit(double amount){
			account->deposit(amount);
		}
		void freeze(){
			cout<<"Account freezed....."<<endl;
		}
};
class manager:public employee{
	private:
		overdraft * account;
	public:
		manager(string name,string id,overdraft* account):employee(name,id),account(account){}
		void updatelimit(double newlimit){
			overdraft(account->getaccount(),account->getbalance(),newlimit);
			cout<<"Overdrafted limit updated"<<endl;
		}
};
int main(){
	savingaccount sa("234143",5000,5.0);
	businessaccount ba("56789",0,10);
	overdraft odraft("13234",7000,2000);
	cout<<"Saving account balance: "<<sa.getbalance()<<endl;
	sa.apply();
	cout<<"saving account balance after applying interest rate: "<<sa.getbalance()<<endl;
	cout<<"Business account balance:"<<ba.getbalance()<<endl;
	ba.deposit(500000);
	ba.applytax();
	odraft.checkoverdraftlimit(5000);
	customer mehrwan("mehrwan","1234",&sa);
	cout<<"Customer account"<<endl;
	mehrwan.withdraw(1000);
	cout<<"Teller account"<<endl;
	teller sanaullah("Sanaullah","56732",&sa);
	sanaullah.freeze();
	cout<<"Manager Account"<<endl;
	manager harsh("HARSH","45678",&odraft);
	harsh.updatelimit(3000);
	
}
