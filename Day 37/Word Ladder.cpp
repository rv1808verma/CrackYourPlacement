// https://leetcode.com/problems/word-ladder/description/

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(s.find(endWord) == s.end()) return 0;
        
        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        s.erase(beginWord);

        while(!q.empty()){

            string s1 = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(s1 == endWord){
                cout << q.front().second; 
                return dist;            
            }

            for(int j = 0;j<s1.size();j++){
                char original = s1[j];
                for(char i = 'a';i<='z';i++){
                    s1[j] = i;
                    if(s.find(s1) != s.end()){
                        q.push({s1, dist + 1});
                        s.erase(s1);
                    }
                }
                s1[j] = original;
            }
           
        } 
        return 0;  
    }
