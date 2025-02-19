#include<iostream>
using namespace std;
class invoice{
	private:
	string partno;
	string description;
	int quantity;
	double price;
	double invoiceamount;
	public:
		invoice(string partno, string description,int quantity,double price){
			this->partno=partno;
			this->description=description;
			this->quantity=quantity;
			this->price=price;
			setinvoiceamu(this->quantity,this->price);
		}
		void setinvoiceamu(int quantity,double price){
			if(price<0 || quantity<0 ){
				invoiceamount=0;
			}
			else{
			invoiceamount= price*quantity;
		}}
		double getinvoiceamu(){
			return invoiceamount;
		}
		void display(){
			cout<<"Part no: "<<partno<<endl;
			cout<<"Description: "<<description<<endl;
			cout<<"Quantity: "<<quantity<<endl;
			cout<<"price: "<<price<<endl;
			cout<<"Total invoice amount: "<<getinvoiceamu()<<endl;
		}
};
int main(int argc ,char*argv[]){
	string part=argv[1];
	string desc=argv[2];
	int quan=stoi(argv[3]);
	double price=stod(argv[4]);
	invoice bill(part,desc,quan,price);
	bill.display();
}
