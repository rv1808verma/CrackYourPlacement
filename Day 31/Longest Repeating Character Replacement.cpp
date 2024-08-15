// https://leetcode.com/problems/longest-repeating-character-replacement/

    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);  
        int n = s.size();
        int ans = 0;
        int i = 0;
        int maxFreq = 0;

        for (int j = 0; j < n; j++) {
            freq[s[j] - 'A']++; 
            maxFreq = max(maxFreq, freq[s[j] - 'A']);  
            while (j - i + 1 - maxFreq > k) {
                freq[s[i] - 'A']--; 
                i++; 
            }
            ans = max(ans, j - i + 1); 
        }
        return ans;    
    }
