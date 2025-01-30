#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
	int max= stoi(argv[1]);
	int smax= stoi(argv[1]);
	for(int i=1;i<argc;i++){
		if(max<stoi(argv[i])){
			max=stoi(argv[i]);
		}
	}
	for(int i=0;i<argc;i++){
		if(smax<atoi(argv[i]) && atoi(argv[i])!=max){
		 	smax= atoi(argv[i]);
		}
	}
	cout<<"second highest number: "<<smax;
	
}
