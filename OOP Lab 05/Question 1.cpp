#include<iostream>
using namespace std;

class Engine{
	public:
		Engine(){
			cout<<"Engine Created."<<endl;
		}
		~Engine(){
			cout<<"Engine Destroyed."<<endl;
		}
		bool f=false;
		void start(){
			cout<<"Engine Started."<<endl;
			f=true;
		}
		void stop(){
			cout<<"Engine Stop."<<endl;
			f=true;
		}
};
class car{
	Engine engine;
	public:
		car(){
			cout<<"Car Created."<<endl;
		}
		void startcar(){
			engine.start();
		}
		void stopcar(){
			engine.stop();
		}
		~car(){
			cout<<"car destroyed."<<endl;
		}
};
int main(){
	car Car;
	Car.startcar();
	Car.stopcar();
}