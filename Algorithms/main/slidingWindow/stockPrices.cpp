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