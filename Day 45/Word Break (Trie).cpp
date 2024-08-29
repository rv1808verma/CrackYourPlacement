// https://www.geeksforgeeks.org/problems/word-break-trie--141631/1

    int wordBreak(string A, vector<string> &B) {
        //code here
        int n = A.length();
        unordered_set<string> dict(B.begin(), B.end());

        vector<int> dp(n + 1, 0);
        dp[0] = 1; 

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(A.substr(j, i - j)) != dict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
