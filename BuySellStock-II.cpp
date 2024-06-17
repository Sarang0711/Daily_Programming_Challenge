#include<iostream>
#include<vector>
#include <climits>

using namespace std;

// Problem Statement
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

// Sol :

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int total = 0;
        int currProfit = 0;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i] < min) {
                min = prices[i];
            }
            else {
                currProfit = prices[i] - min;
                min = prices[i];
                total += currProfit;

            }
        }
        return total;
    }
};