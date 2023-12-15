// Problem Statement:
// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Sol 1:

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>arr;

        for(int i=1; i<= numRows; i++) {
            vector<int>inner(i);
            arr.push_back(inner);
        }
        for(int i=0; i < numRows; i++) {
            arr[i][0] = 1;
            arr[i][i] = 1;
            for(int j=1; j < i; j++) {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
        return arr;
    }
};

// Sol2:

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>arr;

        for(int i=0; i< numRows; i++) {
            vector<int>inner(i+1, 1);

            for(int j=1; j < i; j++) {
                inner[j] = arr[i-1][j-1] + arr[i-1][j];
            }
            
            arr.push_back(inner);
        }
       
        return arr;
    }
};