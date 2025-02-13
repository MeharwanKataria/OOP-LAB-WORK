//Create a class User with two public fields: int Age and string Name. In the Main method, create an object of class
//User and set Name to &quot;Teo&quot; and Age to 24. Then, output to the screen: &quot;My name is {Name} and I&#39;m {Age} years
//old.&quot; using object fields for Name and Age.

#include<iostream>
#include<string>

using namespace std;

class user{
	public:
	int age;
	string name;
	
		void setdetails(string name,int age){
			this->age=age;
			this->name=name;
		}
		void dis(){
			cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;
		}
};
int main(int argc, char*argv[]){
	user user1;
	user1.setdetails("Teo",24);
	user1.dis();
}
