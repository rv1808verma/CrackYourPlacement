// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

    int maxProfit(vector<int>&a) {
        int sum=0;
        for(int i=1;i<a.size();i++){
            int t=a[i]-a[i-1];
            if(t>0)
            sum+=t;
        }
        return sum;
    }
