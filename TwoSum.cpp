#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int twoSum(int arr[], int n, int target) {
  int count = 0;
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      if(arr[i] + arr[j] == target) {
        count++;
      }
    }
  }
  return count;
}

// * Optimal Sol

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> numMap;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int complement = target - nums[i];
            if(numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
}

};

int main() {
  int arr[] = {2, 4, 6, 3, 7, 5, 8};
  int target = 9;
  int size = sizeof(arr)/sizeof(int);
  cout<<"The number of pairs whose sum is "<<target<<" is "<<twoSum(arr, size, target);
  return 0;
}