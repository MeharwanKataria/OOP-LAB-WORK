#include<iostream>
#include<cstdlib>
using namespace std;
void addarray(void *arr, int size,int *sum) {
    int* array = (int*)arr;
    for (int i = 0; i < size; i++) {
        *sum += array[i];
        cout<<array[i]<<" "<<endl;
    }
}

int main(int argc, char* argv[]) {
 

    int s = argc - 1;
    int arr[s];
    for (int i = 0; i < s; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
int sum=0;
    addarray(arr, s,&sum);
    cout << "Sum of the array using Void Function: " << sum<< endl;
    return 0;
}
