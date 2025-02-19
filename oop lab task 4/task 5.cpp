#include<iostream>
using namespace std;
class account{
	private:
		double accountbal=0;
	public:
		void credit(double add){
			accountbal+=add;
			cout<<"Amount added Successfully"<<endl;
		}
		void debit(double withdraw){
			if(withdraw>accountbal) {
			cout<<"Not enough balance to withdraw"<<endl;
			return;}
			else{
			accountbal-=withdraw;
			cout<<"Amount withdraw successfully"<<endl;}
		}
		double getbal(){
			return accountbal;
		}
};
int main(int argc, char*argv[]){
	account customer;
	int choice;
	while(1){
	cout<<"\n1.Add amount.\n2.Withdraw amount.\n3.check balance.\n4.Exit.\nplease select the option."<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			double amount;
			cout<<"Enter the amount to add."<<endl;
			cin>>amount;
			customer.credit(amount);
			cout<<"New balance: "<<customer.getbal();
		break;
		case 2:
			double withdraw;
			cout<<"Enter the amount to withdraw. "<<endl;
			cin>>withdraw;
			customer.debit(withdraw);
			cout<<"New balance: "<<customer.getbal();
		break;
		case 3:
			cout<<"Net amount Balance: "<<customer.getbal();
		break;
		case 4:
			cout<<"Thank you"<<endl;
			return 0;
		break;
}}}
