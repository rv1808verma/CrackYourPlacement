// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> curr(k1+1,vector<int>(2,0));
        vector<vector<int>> prev(k1+1,vector<int>(2,0));
        int ans=0;
        for(int k=1;k<=k1;k++) prev[k][0]=-v[0];
        for(int i=1;i<v.size();i++)
        {
            for(int k=1;k<=k1;k++)
            {
                curr[k][0]=max(prev[k-1][1]-v[i],prev[k][0]);
            }
            for(int k=1;k<=k1;k++)
            {
                curr[k][1]=max(prev[k][0]+v[i],prev[k][1]);
                ans=max(ans,curr[k][1]);
            }
            prev=curr;
        }
        return ans;    
    }
