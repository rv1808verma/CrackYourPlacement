// https://www.geeksforgeeks.org/problems/minimum-swaps/1

	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<pair<int,int>>temp(n);
	    for(int i=0; i<n; i++) temp[i]={nums[i],i};
	    
	    sort(temp.begin(),temp.end());
	    
	    int cnt=0;
	    for(int i=0; i<n; i++){
	        if(temp[i].second==i) continue;
	        else{
	            cnt++;
	            swap(temp[i],temp[temp[i].second]);
	            i--;
	        }
	    }
	    return cnt;
	}
