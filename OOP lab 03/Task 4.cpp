#include<iostream>
#include<string>

using namespace std;
class employee{
	string firstname;
	string lastname;
	double salary=0;
	
	public:
		void setdetails(string f, string l, double sal){
			firstname=f;
			lastname=l;
			if(sal<0) sal=0.0;
			else salary=sal;
		}
		void getdetails(){
			cout<<"First name: "<<firstname<<endl;
			cout<<"Last name: "<<lastname<<endl;
			cout<<"Salary: "<<salary<<endl;
		}
		void increment(double salary){
			this->salary=salary+salary*0.10;
		
		}
};
int main(int argc, char* argv[]){
	employee e1;
	employee e2;
	string firstname1=argv[1];
	string lastname1=argv[2];
	double sal=stoi(argv[3]);
	string firstname2=argv[4];
	string lastname2=argv[5];
	double sal2=stoi(argv[6]);
	e1.setdetails(firstname1,lastname1,sal);
	e2.setdetails(firstname2,lastname2,sal2);
	cout<<"Before increment of salary."<<endl;;
	cout<<"Employee 1 details: "<<endl;
	e1.getdetails();
	cout<<"Employee 2 details: "<<endl;
	e1.getdetails();
	e1.increment(sal);
	e2.increment(sal2);
	cout<<"After increment of salary."<<endl;
	e1.getdetails();
	e2.getdetails();
}
