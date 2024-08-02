// https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1

bool check(string s)
    {
        int low=0,high=s.size()-1;
        while(low<high)
        {
            if(s[low]!=s[high]) return false;
            low++;
            high-- ;
        }
        return true;
    }
    void fun(int i, string s,vector<vector<string>>&ans, vector<string>&temp)
    {
        if(i==s.size())
        {
            ans.push_back(temp);
            return ;
        }
        
        string x;
        
        for(int index=i;index<s.size();index++)
        {
            x.push_back(s[index]);
            if(check(x))
            {
                temp.push_back(x);
                fun(index+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) 
    {
        vector<vector<string>>ans;
        vector<string>temp;
        fun(0,s,ans,temp);
        return ans ;
    }
