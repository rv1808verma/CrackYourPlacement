// https://leetcode.com/problems/task-scheduler/

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequencies(26, 0);
        for (char task : tasks) {
            frequencies[task - 'A']++;
        }
        
        sort(frequencies.begin(), frequencies.end(), greater<int>());

        int maxFreq = frequencies[0];

        int idleTime = (maxFreq - 1) * n;
        for (int i = 1; i < frequencies.size() && frequencies[i] > 0; i++) {
            idleTime -= min(frequencies[i], maxFreq - 1);
        }
        
        idleTime = max(0, idleTime);
        
        return tasks.size() + idleTime;    
    }
