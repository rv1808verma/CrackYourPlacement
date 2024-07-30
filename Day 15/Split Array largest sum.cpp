// https://leetcode.com/problems/split-array-largest-sum/

int check(int mid, int n, int k, vector<int>& nums){
    int last_painter_time_left=0;
    int number_of_painter_spawned=0;

    for(int i=0; i<n; i++){
        if(last_painter_time_left>=nums[i]) last_painter_time_left-=nums[i];
        else{
            number_of_painter_spawned++;
            
            if(number_of_painter_spawned>k) return 0;

            last_painter_time_left=mid;
            if(last_painter_time_left>=nums[i]) last_painter_time_left-=nums[i];
            else return 0;
        }
    }
    return 1;
}

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return -1;
        long long sum=0;
        for(int i=0; i<n; i++) sum+=nums[i];
        int ans=-1;
        int low=0, high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,n,k,nums)==1){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;   
    }
