#include<iostream>
#include<cmath>
using namespace std;
class circle{
	private:
	float radius;
	public:
		circle(double radius){
		this->radius=radius;
		}
		double getarea(){
			return M_PI*radius*radius; 
		}
		double getperimeter(){
			return M_PI*2*radius;
		}
};
int main(int argc, char *argv[]){
	circle circ(stof(argv[1]));
	double area=circ.getarea();
	double perimeter=circ.getperimeter();
	cout<<" Area: "<<area<<endl;
	cout<<" Perimeter: "<<perimeter<<endl;
}
