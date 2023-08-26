// Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k. If a window does not contain a negative integer, then print 0 for that window.

#include<iostream>
using namespace std;

void findNegative(int arr[], int n, int k) {
    for(int i=0; i<(n-k+1); i++) {
        int start = i;
        int end = start+k-1;
        int flag =0;
        while(start<=end) {
            if(arr[start] < 0) {
                cout<<arr[start]<<" ";
                flag=1;
                break;
            }
            start++;
        }
        if(flag == 0) {
            cout<<0<<" ";
        }
    }
}

int main() {
    int n, k;
    cout<<"Enter the size of array \n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array \n";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<"Enter the window size (less than size of arr) \n";
    cin>>k;
    cout<<"The negative elements in each window are as follows \n";
    findNegative(arr, n, k);
    return 0;
}