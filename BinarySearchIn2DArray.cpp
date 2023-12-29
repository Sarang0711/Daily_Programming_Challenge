#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = m*n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                low = mid + 1;
            }
            else {
                high = mid-1;
            }

        }
       return false;
    }
};

// Approach
// If index = i, and no. of columns in the matrix = m, the index i corresponds to the cell with
// row = i / m and col = i % m. More formally, the cell is (i / m, i % m)(0-based indexing).