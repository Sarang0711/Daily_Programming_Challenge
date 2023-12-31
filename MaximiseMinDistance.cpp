#include<iostream>
#include<algorithm>

using namespace std;

bool isFeasible(int arr[], int n, int k, int mid) {
    int pos = arr[0];
    int elements = 1;
    for(int i=1; i<n; i++) {
        if(arr[i] - pos >= mid) {
            pos = arr[i];
            elements++;
            if(elements == k) {
                return true;
            }
        }
    }
    return false;
}

int largetMinDistance(int arr[], int n, int k) {
    sort(arr, arr+n);
    int left = 1, right = arr[n-1];
    int result = -1;

    while(left < right) {
        int mid = (left+right)/2;
        if(isFeasible(arr, n, k, mid)) {
            result = max(result, mid);
            left = mid+1;
        }
        else {
            right = mid;
        }
    }
    return result;
}

int main() {    

    int arr[] = {1, 2, 8, 4, 9};
    int n= sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout<<"Largest minimum distance is "<<largetMinDistance(arr, n, k)<<endl;
    return 0;
}