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