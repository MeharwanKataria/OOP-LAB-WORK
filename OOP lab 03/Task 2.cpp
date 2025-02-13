//Create a class called Date that includes three pieces of information as instance variables—a month (typeint), a day
//(typeint) and a year (typeint). Provide a method displayDate that displays the month, day and year separated by
//forward slashes(/). Write a test application named DateTest that demonstrates classDate’s capabilities.

#include<iostream>
#include<string>

using namespace std;

class date{
	int month;
	int day;
	int year;
	
	public:
		void setdate(int month,int day, int year){
			this->month=month;
			this->day=day;
			this->year;
		}
		void testapplication(int month,int day, int year){
			if(month>12 && day>31){
				cout<<"invalid date;"<<endl;
			}
			else cout"Date: "<<month<<"/"<<day<<"/"<<year<<endl;
		}
};
int main(int argc, char* argv[]){
	date checkdate;
	int mon=stoi(argv[1]);
	int day=stoi(argv[2]);
	int year=stoi(argv[3]);
	
	checkdate.setdate(mon,day,year);
	checkdate.testapplication(mon,day,year);
}
