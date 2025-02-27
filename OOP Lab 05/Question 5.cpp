#include<iostream>
using namespace std;
class car{
	private:
		mutable string engine="V6 engine";
		mutable string horsepower="2300";
		mutable int capacity=5;
		mutable int nospeaker=2;
	public:
		void change()const{
		engine="V8 turbo zx";
		horsepower="3200-4x4";
		capacity=6;
		int nospeaker=7;
		}
		void display(){
			cout<<"Engine: "<<engine<<endl;
			cout<<"Horsepower: "<<horsepower<<endl;
			cout<<"Capacity: "<<capacity<<endl;
			cout<<"No of Speaker: "<<nospeaker<<endl;
		}
};
int main(int argc ,char*argv[]){
	car vigo;
	vigo.display();
	vigo.change();
	cout<<"After changing: "<<endl;
	vigo.display();
}
