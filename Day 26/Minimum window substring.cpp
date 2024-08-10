//  https://leetcode.com/problems/minimum-window-substring/

    string minWindow(string s, string t) {
        int head=0, tail=0, mini=INT_MAX, start_pos=0, n=0;
        int map[128]={};

        for(auto it:t) map[it]++;

        for(head=0; head<s.size(); head++){
            map[s[head]]--;
            if(map[s[head]]>=0) n++;

            while(n==t.size()){
                if(mini>(head-tail+1)){
                    mini=head-tail+1;
                    start_pos=tail;
                }
                map[s[tail]]++;

                if(map[s[tail]]>0) n--;
                tail++;
            }
        }
        return mini==INT_MAX?"": s.substr(start_pos,mini);  
    }
