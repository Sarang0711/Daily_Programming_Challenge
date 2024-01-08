// Description
// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

// Return the modified image after performing the flood fill.


//* Sol:

#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, vector<int>delrow, vector<int>delcol, int sr, int sc, int initColor, int color) {
        
        int n = image.size();
        int m = image[0].size();
        ans[sr][sc] = color;
        for(int i=0; i<4; i++) {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initColor && ans[nrow][ncol] != color) {
                ans[nrow][ ncol] = color;
                dfs(image, ans, delrow, delcol, nrow, ncol, initColor, color);
            }
        }

    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int initColor = image[sr][sc];
        vector<int>delrow= {-1, 0, 1, 0};
        vector<int>delcol = {0, -1, 0, 1};
       dfs(image, ans, delrow, delcol, sr, sc, initColor, color);
        return ans;
    }
};

// Sol 2:

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int initColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<int>itr1= {-1, 0, 1, 0};
        vector<int>itr2 = {0, -1, 0, 1};
        queue<pair<int, int>>que;
        que.push({sr, sc});
        
        while(!que.empty()) {
            sr = que.front().first;
            sc = que.front().second;
            que.pop();
            ans[sr][sc] = color;

            for(int i=0; i<4; i++) {
                int nrow = sr + itr1[i];
                int ncol = sc + itr2[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initColor && ans[nrow][ncol] != color) {
                    ans[nrow][ ncol] = color;
                    que.push({nrow, ncol});
                }
            }

        }
        return ans;
    }
};