#include<iostream>
#include<vector>
#include <climits>

using namespace std;

// Problem Statement
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Sol :

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int maxi = 0;
        int currProfit = 0;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i] < min) {
                min = prices[i];
            }
            currProfit = prices[i] - min;
            maxi = std::max(maxi, currProfit);
            
        }
        return maxi;
    }

}; 