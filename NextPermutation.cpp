// Problem Statement:
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        for(int i = n-2; i>= 0; i--) {
            if(nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            int temp = nums[index];
            for(int i=n-1; i> index; i--) {
                if(nums[i] > temp) {
                    swap(nums[index], nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+index+1, nums.end());
        }   
    }
};