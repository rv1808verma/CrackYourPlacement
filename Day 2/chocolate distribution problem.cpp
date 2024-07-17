// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long mini=LLONG_MAX;
        int i=0, j=m-1;
        while(i<=j && j<=n-1){
            long long temp=a[j]-a[i];
            mini=min(mini,temp);
            i++;
            j++;
        }
        return mini;
    }
