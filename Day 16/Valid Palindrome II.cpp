// https://leetcode.com/problems/valid-palindrome-ii/description/

bool palindrome(string s){
    int i=0, j=s.length()-1;
    while(i<=j){
        if(s[i]!=s[j]) return false;
        else{
            i++;
            j--;
        }
    }
    return true;
}

    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return palindrome(s.substr(0,i)+s.substr(i+1)) || palindrome(s.substr(0,j) + s.substr(j+1));
            }
        }
        return true;
    }
