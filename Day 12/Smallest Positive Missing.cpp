// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        vector<int>v;
        
        for(int i=0;i<n;i++){
            if(arr[i]>0) v.push_back(arr[i]);
        }
        sort(v.begin(),v.end());
        unique(v.begin(),v.end());
        int j;
        for(j=0;j<v.size();j++){
            if(j+1!=v[j]) return j+1;
        }
        return j+1;
    } 
