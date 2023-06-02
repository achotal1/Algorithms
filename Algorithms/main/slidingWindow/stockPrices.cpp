/*
Given an array where the element at the index i represents the price of a stock on day i, 
find the maximum profit that you can gain by buying the stock once and then selling it.

*/

#include<limits>
int MaxProfit(vector<int> stockPrices)
{
    int mini = numeric_limits<int>::max();
    int maxProfit = 0, windowStart(0);
    for(int windowEnd = 0; windowEnd < stockPrices.size(); windowEnd++){
        mini = min(mini, stockPrices[windowEnd]);
        if(stockPrices[windowEnd] == mini){
            windowStart = windowEnd;
        }
        else if(stockPrices[windowEnd] - mini > maxProfit){
            maxProfit = stockPrices[windowEnd] - mini;
        }
    }
    return maxProfit;
}

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int windowStart = 0;
        int mx = 0;
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
            mx = max(nums[windowEnd] - nums[windowStart], mx);
            if(nums[windowEnd] < nums[windowStart]){
                windowStart = windowEnd;
            }
        }
        return mx < 0 ? 0 : mx;
    }
};