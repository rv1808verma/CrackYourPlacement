// https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>q;
        
        long long int i=startFuel,ans=0,j=0;
        
        while(target-i>0){
            while(j<stations.size() && i>=stations[j][0]){
                q.push(stations[j][1]);
                j++;
            }
            if(i<target){
                if(q.empty())return -1;
                ans++;
                i+=q.top();
                q.pop();
            }
        }
        return ans;    
    }
