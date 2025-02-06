#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
	int sum=0;

	for(int i=1;i<argc;i++){
	sum+=atoi(argv[i]);}

	cout<<"Sum:"<<sum;
	
}
