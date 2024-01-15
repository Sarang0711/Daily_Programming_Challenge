// ? Description:
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.



// * sol 1: Dynamic programming 
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {
private: 
    int countPaths(int i, int j, int m, int n, vector<vector<int>>&dp) {
        if(i >= m || j >= n) {
            return 0;
        }
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        else {
           return dp[i][j] = countPaths(i+1, j, m, n, dp) + countPaths(i, j+1, m, n, dp);
        }
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return countPaths(0, 0, m, n, dp);

    }
};



// * sol2: Combinations

class Solution {
public:
    int uniquePaths(int m, int n) {
       int N = m + n -2;
       int r = m - 1;
       double res = 1;

       for(int i=1; i <= r; i++) {
           res = res * (N - r + i) / i;
       }
        return (int)res;
    }
};
