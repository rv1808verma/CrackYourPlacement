// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

int check(int mid, int n, int k, int arr[]){
    int last_painter_time_left=0;
    int number_of_painter_spawned=0;

    for(int i=0; i<n; i++){
        if(last_painter_time_left>=arr[i]) last_painter_time_left-=arr[i];
        else{
            number_of_painter_spawned++;
            
            if(number_of_painter_spawned>k) return 0;

            last_painter_time_left=mid;
            if(last_painter_time_left>=arr[i]) last_painter_time_left-=arr[i];
            else return 0;
        }
    }
    return 1;
}
    
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n) return -1;
        long long sum=0;
        for(int i=0; i<n; i++) sum+=arr[i];
        int ans=-1;
        int low=0, high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,n,m,arr)==1){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
