#include <iostream>
#include<vector>
#include<queue>
using namespace std;

// Description: 
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


// Sol:
// ? If diagonal elements are considered as neighbours
class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>>que;
        que.push({row, col});


        while(!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            
            for(int delrow= -1; delrow <= 1; delrow++) {
                for(int delcol = -1; delcol <= 1; delcol++) {
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
                        visited[nrow][ncol] = 1;
                        que.push({nrow, ncol});
                    }
                }
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m,0));
        int cnt = 0;
        for(int row=0; row < n; row++) {
            for(int col=0; col<m; col++) {
                if(!visited[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, visited, grid);
                }
            }
        
        }
        return cnt;
    }
};


// ? If diagonal elements are not considered as neighbours

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>>que;
        que.push({row, col});


        while(!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            
            vector<int> r = {-1, 0, 1, 0};
            vector<int> c = {0, -1, 0, 1};

            for(int ir = 0; ir<4; ir++) {
                    int nrow = row + r[ir];
                    int ncol = col + c[ir];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
                        visited[nrow][ncol] = 1;
                        que.push({nrow, ncol});
                    }
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m,0));
        int cnt = 0;
        for(int row=0; row < n; row++) {
            for(int col=0; col<m; col++) {
                if(!visited[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, visited, grid);
                }
            }
        
        }
        return cnt;
    }
};