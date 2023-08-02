//Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]

#include<iostream>
using namespace std;

void occurrences(int arr[], int n, int target) {
  int cnt = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] == target) {
      cnt++;
    }
    else if(arr[i] > target) {
      break;
    } 
  }
  cout<<"The occurrence of "<<target<<" is "<<cnt;
}

int main() {
  int arr[6] = {2, 4, 4, 4, 7, 12};
  int size = sizeof(arr)/sizeof(int);
  int target = 4;
  occurrences(arr, size, target);
  return 0;
}