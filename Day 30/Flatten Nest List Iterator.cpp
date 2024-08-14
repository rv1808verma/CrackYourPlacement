// https://leetcode.com/problems/flatten-nested-list-iterator/

    queue<int> q;
    NestedIterator(vector<NestedInteger> &nestedList) {
       flatten(nestedList, q);   
    }

    void flatten(vector<NestedInteger> &nestedList, queue<int> &q) {
        int n = nestedList.size();
        for(int i = 0; i < n; i++) {
            if(nestedList[i].isInteger()) {
                q.push(nestedList[i].getInteger());
            }
            else {
                flatten(nestedList[i].getList(), q);
            }
        }
    }

    
    int next() {
        int x = q.front();
        q.pop();
        return x;     
    }
    
    bool hasNext() {
        return !q.empty();
    }
