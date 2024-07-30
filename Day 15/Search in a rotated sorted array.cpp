// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) return mid;

            //if left part is sorted:
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;  //element exists:
                }
                else {
                    low = mid + 1;  //element does not exist:
                }
            }
            else { //if right part is sorted:
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;  //element exists:
                }
                else {
                    high = mid - 1;  //element does not exist:
                }
            }
        }
        return -1;    
    }
