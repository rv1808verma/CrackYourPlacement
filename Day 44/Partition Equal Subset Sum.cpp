// https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        unordered_set<int> us;
        for(int i = 0 ;i<n;i++){
            sum += arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        sum/=2;
        for(int i = n-1;i>=0;i--){
            vector<int> v;
            for(auto j = us.begin(); j!=us.end();j++){
                int num = arr[i]+ *j;
                if(num<sum){
                    v.push_back(num);
                }
                if(num==sum){
                    return 1;
                }
            }
            for(int j = 0 ;j<v.size();j++){
                us.insert(v[j]);
            }
            if(arr[i]<sum){
                us.insert(arr[i]);
            }
            if(arr[i]==sum){
                return 1;
            }
        }
        return 0;
    }
