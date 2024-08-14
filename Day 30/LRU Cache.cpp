// https://leetcode.com/problems/lru-cache/description/

    unordered_map<int,int>m;
    unordered_map<int,list<int>:: iterator> keyPosition;
    int size;
    int cap;
    list<int>LRUList;
    LRUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        list<int>:: iterator it=keyPosition[key];
        LRUList.erase(it);
        LRUList.push_front(key);
        keyPosition[key]=LRUList.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            get(key);
            m[key]=value;
        }else{
            if(size==cap){
                int lru=LRUList.back();
                keyPosition.erase(lru);
                m.erase(lru);
                LRUList.pop_back();
                size--;
            }
            m[key]=value;
            LRUList.push_front(key);
            keyPosition[key]=LRUList.begin();
            size++;
        }
    }
