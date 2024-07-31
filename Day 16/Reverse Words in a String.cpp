// https://leetcode.com/problems/reverse-words-in-a-string/description/

   // (Perfect use of std::stringstream)
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";

        string result = "";
        //By default stringstream tokenizes on ' ' (space character)
        //Know more : https://github.com/MAZHARMIK/Cpp-STL-Quick-Help/blob/main/README.md
        while(ss >> token) {
            result = token + " " + result;
        }

        return result.substr(0, result.length()-1);
    }

// two pointers
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int i = 0;
        //hero honge hamare l and r jo revrese karenge words ko
        int l = 0, r = 0;
        
        int n = s.length();
        
        while(i < n) {
            while(i < n && s[i] != ' ') { //i ko agar char dikha to r ko dega and i++ and r++
                s[r] = s[i];
                i++;
                r++;
            }
            
            if(l < r) { //l     
                reverse(s.begin()+l, s.begin()+r);
                s[r] = ' ';
                r++;
                l = r;
            }
            i++; 
        }
        s = s.substr(0 , r-1);
        return s;  
    }
