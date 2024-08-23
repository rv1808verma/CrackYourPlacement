// https://leetcode.com/problems/kth-largest-element-in-an-array/

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > minHeap;
        for(int i=0; i < k; i++){
            minHeap.push(nums[i]);
        }
        for(int j=k; j<nums.size(); j++){
            if(nums[j] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[j]);
            }
        }
        return minHeap.top();     
    }
