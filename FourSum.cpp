// Desc

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

//* sol

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        sort(nums.begin(), nums.end());
        set<vector<int>>st;
        for(int start = 0; start<end; start++) {
            if(start > 0 && nums[start] == nums[start-1]) {continue;}
            for(int i=start+1; i < end; i++) {
                int j = i+1;
                int k = end;
                while(j < k) {
                    long long int sum = nums[start];
                    sum += nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    if(sum == target) {
                        st.insert({nums[start], nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                        while(j < k && nums[j] == nums[j-1]) j++;
                        while(k > j && nums[k] == nums[k+1]) k--;
                    }
                    else if(sum < target) {
                        j++;
                    } 
                    else if(sum > target) {
                        k--;
                    }
                }
            }
        }
        vector<vector<int>>ans = {st.begin(), st.end()};
        return ans;
    }
};