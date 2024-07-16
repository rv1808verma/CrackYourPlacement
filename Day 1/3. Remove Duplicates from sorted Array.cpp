// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[j]!=nums[i]){
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
