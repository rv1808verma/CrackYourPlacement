// https://www.geeksforgeeks.org/problems/alien-dictionary/1

    void anss(stack<char>&s,unordered_map<char,vector<char>>&mp,char c,int arr[])
    {
        for(auto i:mp[c])
        {
            if(arr[i-'a']>0)
            {
                arr[i-'a']=0;
                anss(s,mp,i,arr);
            }
        }
        s.push(c);
    }
    
    string findOrder(string dict[], int n, int k) {
        //code here
        unordered_map<char,vector<char>>mp;
        string s,stt;
        stack<char>st;
        char c;
        int j=0,a,b,arr[26]={0};
        for(int i=0;i<n-1;i++)
        {
            s=dict[i];
            stt=dict[i+1];
            a=s.length();
            b=stt.length();
            j=0;
            while(j<a&&j<b)
            {
                if(s[j]==stt[j])
                j++;
                else
                {
                    mp[s[j]].push_back(stt[j]);
                    arr[s[j]-'a']=1;
                    arr[stt[j]-'a']=1;
                    break;
                }
            }
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
            {
                c='a'+i;
                arr[c-'a']=0;
                anss(st,mp,c,arr);
            }
        }
        s="";
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        return s;
    }

