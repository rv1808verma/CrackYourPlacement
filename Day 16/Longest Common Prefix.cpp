// https://leetcode.com/problems/longest-common-prefix/description/

    string longestCommonPrefix(vector<string>& strs) {
        int n=strs[0].length(), m=strs.size(), i, j;
        string res= "";
        char ch;
        for(i=0; i<n; i++){
            ch = strs[0][i];
            for(j=1;j<m; j++) {
                if(strs[j][i]!=ch) return res;
            }
            if(j==m) res+=ch;
        }
        return res;    
    }
