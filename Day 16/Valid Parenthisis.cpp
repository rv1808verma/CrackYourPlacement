// https://leetcode.com/problems/valid-parentheses/

    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(st.empty()) st.push(s[i]);
            else if((st.top()=='(' && s[i]==')') ||
                    (st.top()=='[' && s[i]==']') ||
                    (st.top()=='{' && s[i]=='}'))
                    st.pop();
            else{
                st.push(s[i]);
            }
        }
        if(st.size()==0) return 1;
        else return 0;
    }
