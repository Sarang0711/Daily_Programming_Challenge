// Desc
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Sol:


#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        unordered_map<int, int>numMap;

        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int target = 0 - nums[i] - nums[j];  
                if(numMap.count(target) != 0) {
                    vector<int>temp = {nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                else {

                    numMap[nums[j]] = j;
                }
            }
            numMap.clear();
            
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};

//* Optimal Sol

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++) {
            // if(i != 0 && nums[i] != nums[i-1]) {continue;}
            int start = i+1;
            int end = nums.size()-1;
            int sum = 0;
            while(start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if(sum < 0) {
                    start++;
                }
                else if(sum > 0) {
                    end--;
                }
                else if(sum == 0) {
                    vector<int>temp = {nums[start], nums[i], nums[end]};
                    ans.push_back(temp);
                    start++;
                    end--;

                    while(start < end && nums[start] == nums[start-1]) {
                        start++;
                    }
                    while(start < end && nums[end] == nums[end+1]) {
                        end--;
                    }

                }

            }
            while(i+1 < nums.size() && nums[i] == nums[i+1])  i++;
        }
        return ans;
    }
};