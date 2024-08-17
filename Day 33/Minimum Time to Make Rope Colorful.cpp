// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int i = 0, j = 0;
        int ans = 0;
        while (i < n) {
            while (j < n && colors[j] == colors[i]) j++;
            int s = 0, m = INT_MIN;
            while (i < j) {
                s = s + neededTime[i];
                m = max(m, neededTime[i]);
                i++;
            }
            ans = ans + s - m;
            i = j;
        }
        return ans;        
    }
