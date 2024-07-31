// https://www.geeksforgeeks.org/problems/print-anagrams-together/1

    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>>ans;
        map<string,vector<string>>mp;
        
        for(int i=0; i<string_list.size(); i++){
            string temp=string_list[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(string_list[i]);
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
