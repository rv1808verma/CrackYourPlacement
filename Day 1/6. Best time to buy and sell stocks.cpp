// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int minSoFar=prices[0];
        for(int i=0; i<prices.size(); i++){
            minSoFar=min(minSoFar,prices[i]);
            int profit=prices[i]-minSoFar;
            maxProfit=max(maxProfit,profit);
        }
        return maxProfit;
    }
