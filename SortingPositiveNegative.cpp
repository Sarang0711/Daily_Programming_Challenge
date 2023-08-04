// An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

#include<iostream>
#include<queue>
using namespace std;

void arrange(int arr[], int n) {
  int start = 0;
  int end = n-1;
  int temp;
  while(start < end) {
    if(arr[start] > 0 && arr[end] < 0) {
      temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;

    }
    if(arr[start] > 0 && arr[end] > 0) {
      end--;
    }
    if(arr[start] < 0) {
      start++;
    }
  }
}

int main() {
  int arr[] = {6, 4, 3, 0, -2, -7, -9};
  int size = sizeof(arr) / sizeof(int);
  arrange(arr, size);
  for(int i=0; i<size; i++) {
    cout<<arr[i]<<" ";
  }
  return 0;
}