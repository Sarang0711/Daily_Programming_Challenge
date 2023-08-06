// Given an unsorted array of N integers, find smallest and largest element in optimal way
#include<iostream>
using namespace std;

void minmax(int arr[], int n) {
	int min = arr[0];
	int max = arr[0];
	for(int i=1; i<n; i++) {
		if(arr[i] < min) {
			min = arr[i];
		}
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	cout<<"Minimum number is "<<min<<endl;
	cout<<"Maximum number is "<<max<<endl;
}

int main() {
	int arr[7] = {15, 11, 7, 9, 18, 4, 1};
  	int size = sizeof(arr)/sizeof(int);
	minmax(arr, size);
	return 0;
}