// https://leetcode.com/problems/daily-temperatures/

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>res(n);
        stack<int>st;
        for(int i=n-1;i>=0;i-=1){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i] ) st.pop();
            if(st.empty()) res[i]=0; else res[i]=st.top()-i;
            st.push(i);
        }
        return res;        
    }
