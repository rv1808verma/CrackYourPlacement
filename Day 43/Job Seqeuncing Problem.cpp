// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

    bool static JobPriority(Job a, Job b) {
    return a.profit > b.profit;
}

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, JobPriority);
        int cnt = 0, profit = 0;
        bool done[n] = {0};
        for(int i = 0; i < n; i++) {
            for(int j = arr[i].dead - 1; j >= 0 ; j--) {
                if(done[j] == 0) {
                    done[j] = 1;
                    profit += arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }
        vector<int> result;
        result.push_back(cnt);
        result.push_back(profit);
        return result;
    } 
