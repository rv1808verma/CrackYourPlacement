// https://www.geeksforgeeks.org/problems/phone-directory4628/1

struct Node{
    Node* links[26];
    bool flag ;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch){
        Node* node = new Node();
        links[ch-'a']= node;
    }
    
    Node* get(char ch){ 
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    
    bool getEnd(){
        return flag;
    }
    
};

class Solution{
public:
    Node*node;
    void insert(string word ,Node* root){
        Node*node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
                
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    void printAll(string str , vector<string>&temp , Node* node ){
         
        if(node->getEnd())
        temp.push_back(str);
        
       
        for(int i=0;i<26;i++){
            if(node->containsKey(i+'a')){
                str+=(i+'a');
                printAll(str , temp , node->get(i+'a'));
                str.pop_back();
            }
        }
       
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>ans;
        
        Node* root = new Node();
        for(int i=0;i<n;i++){
           insert(contact[i] , root);
        }
        
        node = root;
        string str = "";
        for(int i=0;i<s.length();i++){
            if(!node->containsKey(s[i])){
                ans.push_back({"0"});
                break;
            }
            
            else{
                vector<string>temp;
                node = node->get(s[i]);
                str+=s[i];
                printAll(str , temp ,node);
               
                ans.push_back(temp);
            }
        }
        
        
        while(ans.size()<s.length()){
            ans.push_back({"0"});
        }
        return ans;
    }
