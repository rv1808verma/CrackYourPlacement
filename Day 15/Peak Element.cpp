// Bitonic Array or Peak Element
#include <bits/stdc++.h>
using namespace std;

bool check(int mid, int arr[]){
    if(mid==6) return 1;
    if(arr[mid] > arr[mid+1]) return 1;
    else return 0;
}
int main(){
    int arr[7]={1,2,3,7,9,2,1};
    int ans=-1;
    int low=0, high=8;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid,arr)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<"\n";
}
