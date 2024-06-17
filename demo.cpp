#include <iostream>
using namespace std;

void print(int (&arr)[4], int n) {
    arr[3] = 9;
    for(int i=0; i<n; i++) {

        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[] = {2, 3, 4, 8};
    int n = sizeof(arr)/sizeof(int);

    print(arr, n);
    return 0;
}