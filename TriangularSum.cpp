// Problem Statement:

// You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).
// The triangular sum of nums is the value of the only element present in nums after the following process terminates:
// Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.
// For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.
// Replace the array nums with newNums.
// Repeat the entire process starting from step 1.
// Return the triangular sum of nums.


// Sol 1:

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp;
        int sum=0;
        int itr = nums.size()-1;
        while(itr > 0) {
            for (int i=0; i<nums.size()-1; i++){
                sum = (nums[i] + nums[i+1]) % 10;
                temp.push_back(sum);
            }
            nums.erase(nums.begin(), nums.end());
            nums = temp;
            temp.erase(temp.begin(), temp.end());
            itr--;
        }
        return nums[0];
    }
};

// Sol 2


class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int itr = nums.size()-1;
        while(nums.size() != 1) {
            for (int i=0; i<nums.size()-1; i++){
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};