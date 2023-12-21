//Problem Statement:
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

//Sol:

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        if(intervals.empty()) {
            return ans;
        }
        sort(intervals.begin(), intervals.end());
        int flag = 0;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            int start1 = ans.back()[0];
            int end1 = ans.back()[1];
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1 >= start2) {
                ans.back()[0] = min(start1, start2);
                ans.back()[1] = max(end1, end2);
            }
            else {
                ans.push_back(intervals[i]);
            }

        }
        return ans;
    }
};