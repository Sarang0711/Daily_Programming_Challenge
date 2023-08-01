// Find the Kth largest element in a given array
#include<iostream>
using namespace std;

int kthLargest(int arr[], int n, int k) {
  int minIndex, temp;
  for(int i=0; i<n; i++) {
    minIndex = i;
    for(int j=i+1; j<n; j++) {
      if(arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
  return arr[n-k];
}

int main() {
  int arr[9] = {2, 7, 1, 3, 8, 4, 6, 9, 5};
  int size = sizeof(arr)/sizeof(int);
  int k = 4;
  cout<<"The "<<k<<"th largest element in the array is "<<kthLargest(arr, size, k);

  return 0;
}