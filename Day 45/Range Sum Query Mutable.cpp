// https://leetcode.com/problems/range-sum-query-mutable/description/

    vector<int>prefix;
    vector<int>nums;
    NumArray(vector<int>& NUMS) {
        nums = NUMS;
        int n = nums.size();
        prefix.resize(n);
        prefix[0] = nums[0];
        for(int i=1; i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    
    void update(int index, int val) {
        int original = nums[index];
        int diffrence = val - original;
        nums[index] = val;
        for(int i=index; i<prefix.size(); i++){
            prefix[i] += diffrence;
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return prefix[right];
        return prefix[right]-prefix[left-1];
    }
