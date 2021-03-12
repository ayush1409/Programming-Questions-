// Problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = INT_MAX, maxTradeI, maxTrade = 0 ;
        
        for(int i = 0 ; i < prices.size() ; i++){
            minSoFar = min(prices[i], minSoFar) ;
            maxTradeI = prices[i] - minSoFar ;
            
            if(maxTradeI > maxTrade)
                maxTrade = maxTradeI ;
        }
        
        return maxTrade ;
    }
};
