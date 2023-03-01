use std::cmp;
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut maxprofit = 0;
        let mut windowStart = 0;
        let mut profit:i32 = 0;
        for (windowEnd,n) in prices.iter().enumerate(){
            if windowEnd == 0{
                continue;
            }
            profit = n - prices[windowStart];
            if profit < 0{
                windowStart += 1;
            }
            else{
                maxprofit = cmp::max(maxprofit, profit);
            }
        }
        maxprofit
    }
}