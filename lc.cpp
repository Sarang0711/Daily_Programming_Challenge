class Solution
{
public:
    int maxIndexProfit(vector<int> &prices)
    {
        int minIndex = 0;
        int maxIndex = 0;
        int maxiProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[minIndex])
            {
                minIndex = i;
            }
            else if (prices[i] > prices[maxIndex])
            {
                maxIndex = i;
                maxiProfit = std::max(maxiProfit, prices[maxIndex] - prices[minIndex]);
            }
        }
        return maxiProfit;
    }
};