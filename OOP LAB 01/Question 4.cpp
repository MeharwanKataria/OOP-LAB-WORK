#include<iostream>
#include <cstdio>
using namespace std;
int main(int argc, char* argv[]){
	float a= stof(argv[1]);
	float b=a*2.2;
	printf("%.2f kilogram = %.2f pounds.",a,b);
}
