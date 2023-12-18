#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

// Problem Statement
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 
// Sol :

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int longestConsecutiveSeq = 0;
        for (int num: nums) {
            if(set.find(num-1) == set.end()) {
                int currentnumber = num;
                int currentConsecutiveSeq = 1;
                
                while(set.find(currentnumber + 1) != set.end()) {
                    currentnumber++;
                    currentConsecutiveSeq++;
                }
            longestConsecutiveSeq = max(longestConsecutiveSeq, currentConsecutiveSeq);
            }
        }
        return longestConsecutiveSeq;
    }
};