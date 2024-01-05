#include<iostream>
using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int start, int end) {
  int index = start - 1;
  int pivot = arr[end];
  for(int i=start; i<end; i++) {
    if(arr[i] <= pivot) {
      index++;
     swap(&arr[index], &arr[i]);
    }
  }
  swap(&arr[index+1], &arr[end]);

  return index+1;
}

void quicksort(int arr[], int start, int end) {
  if(start < end) {
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot-1);
    quicksort(arr, pivot+1, end);
  }

}
int main() {
  int arr[] = {5, 2, 8, 1, 9, 7, 6};
  int size = sizeof(arr)/sizeof(int);

  quicksort(arr, 0, size-1);
  cout<<"Array after sorting\n";
  for(int i=0; i<size; i++) {
    cout<<arr[i]<<" ";
  }
  return 0;
}