// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int i=0, j=n-1;
        int sum=0;
        while(k){
            if(cardPoints[i]>cardPoints[j]){
                sum+=cardPoints[i];
                i++;
            }
            else if(cardPoints[j]>cardPoints[i]){
                sum+=cardPoints[j];
                j--;
            }
            else if(cardPoints[i]==cardPoints[j]){
                if(cardPoints[i+1]>cardPoints[j-1]){
                    sum+=cardPoints[i];
                    i++;
                }else{
                    sum+=cardPoints[j];
                    j--;
                }
            }
            k--;
        }
        return sum;
    }
