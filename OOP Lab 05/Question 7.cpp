#include<iostream>
#include<vector>
using namespace std;
class student{
	private:
		const string rollno;
		const string name;
	public:
		student(string no, string n):rollno(n),name(n){}
		void display(){
			cout<<"Roll no: "<<rollno<<endl;
			cout<<"Name: "<<name<<endl;
		}
};
int main(int argc,char*argv[]){
	student s("24k-0864","Meharwan");
	s.display();
}
