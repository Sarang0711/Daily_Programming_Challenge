#include<iostream>
using namespace std;

void rotateLeft(int arr[],int n, int k) {
    int index;
    int temp[k];
    for(int i=0; i<n; i++) {
        index = (k+i) % n;
        
        if(i < n-k) {
            if(i < k) {
                temp[i] = arr[i];
            }
            arr[i] = arr[index];
        }
        else if (i >= n-k) {
            arr[i] = temp[index];
        }

    }
}   

int main() {
    int arr[7] = {15, 11, 7, 9, 18, 4, 1};
    int size = sizeof(arr)/sizeof(int);
    int k;
    cout<<"Enter the number of times an array should be left rotated \n";
    cin>>k;
    rotateLeft(arr, size, k);
    cout<<"Array after left rotation\n";
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}