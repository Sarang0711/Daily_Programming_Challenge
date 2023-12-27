#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.


// Sol1: 
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int>umap;
        vector<int>ans(2);
        int n = grid.size();
        for(int i=1; i<=(n*n); i++) {
            umap[i] =  0;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int num = grid[i][j];
                umap[num]++;
            }
        }
        for(auto x: umap) {
            cout<<x.first<<"  "<<x.second<<endl;
            if(x.second > 1) {
                ans[0] = x.first;
            }
            if(x.second == 0) {
                ans[1] = x.first;
            }
        }
        return ans;
    }
};

// Sol 2:
//? Based on (x+y)(x-y) = (x2-y2) 
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = (grid.size())* (grid.size());
        long long Sn = (n * (n+1))/2;
        long long Sn2 = (n* (n+1)* (2*n+1))/6;
        long long S=0, S2 = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                S += grid[i][j];
                S2 += (long long) grid[i][j]*(long long)grid[i][j];
            }
        }
        long long val1 = S - Sn;
        long long val2 = S2 - Sn2;
        val2 = val2 / val1;
        long long x = (val1 + val2)/2;
        long long y = (x - val1);
        
        return {(int)x, (int)y};
    }
};