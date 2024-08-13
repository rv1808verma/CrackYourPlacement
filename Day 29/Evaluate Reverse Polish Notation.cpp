// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int ans = 0, x = 0, y = 0;
        for(int i = 0 ; i < tokens.size(); ++i){
            string s = tokens[i];

            if((s[0]<'0' || s[0]>'9') && s.size() == 1){
               
                x = stk.top();
                stk.pop();
                y = stk.top();
                stk.pop();

                if(s[0] =='+')y+=x;
                if(s[0] =='-')y-=x;
                if(s[0] =='*')y*=x;
                if(s[0] =='/')y/=x;

                stk.push(y);
                continue;
            }

            stk.push(stoi(s));
        }
        return stk.top();   
    }
