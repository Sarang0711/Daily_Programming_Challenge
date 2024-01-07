// Description
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

//* Sol:

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n / 3;
        int ans1, ans2;
        int cnt1 = 0, cnt2=0;
        vector<int>majority;
        for(int num: nums) {
            if(cnt1 == 0 && num != ans2) {
                cnt1++;
                ans1 = num;
            }
            else if(cnt2 == 0 && num != ans1) {
                cnt2++;
                ans2 = num;
            }
            else if(ans1 == num) {
                cnt1++;
            }
            else if(ans2 == num) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0, cnt2=0;
        for(int num : nums) {
            if(num == ans1) {
                cnt1++;
            }
            else if (num == ans2) {
                cnt2++;
            }
        }
        if(cnt1 > target) {
            majority.push_back(ans1);
        }
        if(cnt2 > target) {
            majority.push_back(ans2);
        }
        return majority;
    }
};