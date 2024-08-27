// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int transactions=2*k;
        vector<vector<int>>dp(n+1,vector<int>(transactions+1,0));
        for(int index=n-1;index>=0;index--){
            for(int transaction=transactions-1;transaction>=0;transaction--){
                if(transaction%2==0){
                    dp[index][transaction]=max(-prices[index]+dp[index+1]
                    [transaction+1],dp[index+1][transaction]);
                }
                else{
                    dp[index][transaction]=max(prices[index]+dp[index+1]
                    [transaction+1],dp[index+1][transaction]);
                }
            }
        }
        return dp[0][0];  
    }
