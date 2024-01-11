#include<iostream>
using namespace std;

  int kadanesAlgo(int arr[], int n) {
    int currsum = 0;
    int max= 0;
    for(int i=0; i<n; i++) {
      currsum = currsum + arr[i];
      if(currsum > max) {
        max = currsum;
      }
      if(currsum < 0) {
        currsum = 0;
      }
    }
    return max;
  }


int main() {
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int size = sizeof(arr)/sizeof(int);
  cout<<kadanesAlgo(arr, size);
  return 0;
}