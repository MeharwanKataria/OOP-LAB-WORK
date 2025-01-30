#include<iostream>
#include <cstdio>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int a = argc - 3;
    float sum = 0;
    float avg = 0;

    for(int i = 3; i < argc; i++) {
        sum += stof(argv[i]);
    }
    avg = sum / a;

    printf("%s %s", argv[1],argv[2]);
	printf("\nTest score: ");
    for(int i = 3; i < argc; i++) {
        printf("%.2f ", stof(argv[i]));
    }
    printf("\naverage: %.2f\n", avg);

}
