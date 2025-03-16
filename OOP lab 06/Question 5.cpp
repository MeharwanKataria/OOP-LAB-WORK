#include<iostream>
using namespace std;

class vehicle{
	protected:
		double price;
	public:
		vehicle(double price):price(price){}
		virtual void display(){
			cout<<"Vehicle details :"<<endl;
			cout<<"Price: "<<price<<endl;
		}
};
class car:public vehicle{
	protected:
		int seats;
		int doors;
		string fueltype;
	public:
		car(double price,int seats,int doors,string fueltype):vehicle(price),seats(seats),doors(doors),fueltype(fueltype){}
		virtual void display() override{
			vehicle::display();
			cout<<"Seating capacity : "<<seats<<endl;
			cout<<"No of Doors"<<doors<<endl;
			cout<<"Fueltype: "<<fueltype<<endl;
		}
};
class motorcycle: public vehicle{
	protected:
		int noofcylinder;
		int noofgears;
		string fueltype;
		string model;
	public:
		motorcycle(double price,int noofcylinder,int noofgears,string fueltype,string model):vehicle(price),noofcylinder(noofcylinder),noofgears(noofgears),
		fueltype(fueltype),model(model){}
		virtual void display() override{
		vehicle::display();
		cout<<"No of Cylinder: "<<noofcylinder<<endl;
		cout<<"No of Gears: "<<noofgears<<endl;
		cout<<"Fueltype: "<<fueltype<<endl;
		cout<<"Model: "<<model<<endl;
		}
};
class audi:public car{
	private:
		string model;
	public:
		audi(double price,int seats,int doors,string fueltype,string model):car(price,seats,doors,fueltype),model(model){}
		void display() override{
		car::display();
		cout<<"Model type: "<<model<<endl;}
};
class yamha:public motorcycle{
	private:
		string maketype;
	public:
		yamha(double price ,int noofcylinder,int noofgears,string fueltype,string model,string maketype):
		motorcycle(price,noofcylinder,noofgears,fueltype,model),maketype(maketype){}
		void display()override{
		motorcycle::display();
		cout<<"Make type: "<<maketype<<endl;}
};
int main(){
	yamha myyamha(150000, 2, 6, "Petrol", "HarleyDavidson","cruiser");
	audi myaudi(200000,5,4,"Petrol","etron gtr");
	cout<<"Audi class: "<<endl;
	myaudi.display();
	cout<<"Yamha class: "<<endl;
	myyamha.display();
}
