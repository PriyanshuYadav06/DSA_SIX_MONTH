#include<iostream>
#include<vector>
using namespace std;
int maxsubArraySum(vector<int>nums,int k){
    int n=nums.size();
    int i=0;
    int j=0;
    int sum=0;
    int maxi=INT_MIN;
    while(j<n){
        sum+=nums[j];
        if(j-i+1<k) j++;
        else if(j-i+1==k){
            maxi=max(sum,maxi);
            sum-=nums[i];
            i++;
            j++;
        }
    } 
    return maxi;
}
int main(){
    vector<int>nums={1, 4, 2, 10, 23, 3, 1, 0, 20};
    cout<<maxsubArraySum(nums,4);

    return 0;
}