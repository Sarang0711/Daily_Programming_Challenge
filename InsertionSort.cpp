// 7, 4, 5, 2
#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
  for(int i=1; i<n; i++) {
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
      arr[j] = key;
  }
}



int main() {
  int arr[] = {12, 31, 25, 8, 32, 17};
  int size = sizeof(arr) / sizeof(int);
  insertion_sort(arr, size);
  cout<<"After Sorting array \n";
  for(int i=0; i<size; i++) {
    cout<<arr[i]<<" ";
  }
  return 0;
}