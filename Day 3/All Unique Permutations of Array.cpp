// https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/

    vector<vector<int>> result;
    void solve(int idx, vector<int>& nums, int n) {
        if(idx == n) {
            result.push_back(nums);
            return;
        }
        
        unordered_set<int> uniqueSet;
        for(int i = idx; i < n; i++) {
            
            if(uniqueSet.count(nums[i]) > 0) {
                continue;
            }
            
            uniqueSet.insert(nums[i]);
            
            swap(nums[i], nums[idx]);

            solve(idx+1, nums, n);

            swap(nums[i], nums[idx]);
            
        }
        
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        solve(0, arr, n);
        sort(result.begin(),result.end());
        return result;

    }


// https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/Permutations%20II.cpp
