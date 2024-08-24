// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> nums(n);
        for(int i = 0; i < n; i++) nums[i] = {(double)wage[i] / quality[i], quality[i]};
        sort(nums.begin(), nums.end());

        double ans = DBL_MAX;
        priority_queue<int> Q; 

        int sum = 0;
        for(int i = 0; i < n; i++){
            double ratio = nums[i].first;
            int curr_quality = nums[i].second;
            sum += curr_quality, Q.push(curr_quality);

            if(Q.size() > k) sum -= Q.top(), Q.pop();
            if(Q.size() == k) ans = min(ans, (double)sum * ratio);
        }
        return ans;
    }
