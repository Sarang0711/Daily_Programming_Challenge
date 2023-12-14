#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// Problem Statement
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// Sol 1:

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row;
        vector<int> col;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0){
                    // cout<<"found "<<i<<" "<<j<<endl;
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        for(int i=0; i<row.size(); i++) {
            int r = row[i];
            int c = col[i];
            while(r >= 0) {
                matrix[r][c] = 0;
                r--;
            }
            r = row[i];
            while(r < m) {
                matrix[r][c] = 0;
                r++;
            }
            r = row[i];
            c = col[i];
            while(c >= 0) {
                matrix[r][c] = 0;
                c--;
            }
            c = col[i];
            while(c < n) {
                matrix[r][c] = 0;
                c++;
            }
        }
    }
};

// Sol 2:

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> setRows; 
        unordered_set<int> setColumns; 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    setRows.insert(i);
                    setColumns.insert(j);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(setRows.count(i) > 0 || setColumns.count(j) > 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
