// Problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = INT_MAX, maxTradeI, maxTrade = 0 ;
        
        for(int i = 0 ; i < prices.size() ; i++){
            minSoFar = min(prices[i], minSoFar) ;	// keep track of min price encountered so far
            maxTradeI = prices[i] - minSoFar ;		// calculate trade for the current price
            
            if(maxTradeI > maxTrade)
                maxTrade = maxTradeI ;				// update the maxTrade accordingly
        }
        
        return maxTrade ;
    }
};
