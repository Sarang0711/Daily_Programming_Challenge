// Rotate the array left K times. Accept K value from the user.
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

// Rotate the array right K times, Accept K value from the user

void rotateRight(int arr[],int n, int k) {
    k  = k % n;
    int temp[n];
    for(int i=0; i<n; i++) {
        if(i < k) {
            temp[i] = arr[i + n - k];
        }
        if(i >= k) {
            temp[i] = arr[i - k];
        }
    }
    for(int i=0; i<n; i++) {
        arr[i] = temp[i];
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
    cout<<endl;

    int arr1[7] = {5, 2, 8, 1, 9, 7, 6};
    int size1 = sizeof(arr1)/sizeof(int);
    int k1;
    cout<<"Enter the number of times an array should be right rotated \n";
    cin>>k1;
    rotateRight(arr1, size1, k1);
    cout<<"Array after right rotation\n";
    for(int i=0; i<size1; i++) {
        cout<<arr1[i]<<" ";
    }
    return 0;
}