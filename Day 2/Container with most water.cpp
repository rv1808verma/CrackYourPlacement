// https://leetcode.com/problems/container-with-most-water/

    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int i=0, j=n-1;
        while(i<j){
            int h=min(height[i],height[j]);
            int w=j-i;
            int area=h*w;
            ans=max(area,ans);

            if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
