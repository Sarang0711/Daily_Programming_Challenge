// ? Description:
// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// * sol: Dynamic programming 
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {
private:
    int uniquePaths(vector<vector<int>> &obstacleGrid, vector<vector<int>>&dp, int m, int n, int i, int j) {
        if(i >= m || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        else {
            return dp[i][j] = uniquePaths(obstacleGrid, dp, m, n, i+1, j) + uniquePaths(obstacleGrid, dp, m, n, i, j+1); 
        }
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return uniquePaths(obstacleGrid, dp, m, n, 0, 0);
    }
};
