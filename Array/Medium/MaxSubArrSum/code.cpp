#include <iostream>
#include <vector>
using namespace std;
// Leetcode -> 121

// This is Extreme Brute Force Solution -> O(n^3)
void CalMaxSum(int st,int en,vector<int> &nums,int &ans){
    int sum = 0;
    for(int i=st;i<=en;i++){
        sum+=nums[i];
    }
    ans = max(ans,sum);
}
void PrintSubArr(vector<int> &nums,int &ans)
{
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            CalMaxSum(i,j,nums,ans);
        }
    }
}
// This is Optimal bt not most optimized -> O(n^2)
int MaxSubArrSum1(vector<int> &nums){
    int n= nums.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}
// The most Optimized Solution using Kadanes Algorihtm -> O(n)
int MaxSubArrSum2(vector<int> &nums){
    int n= nums.size();
    int curr_sum=0;
    int max_sum=INT_MIN;
    int startIdx=-1;
    int endIdx=-1;
    int tempStart=-1;

    for(int i=0;i<n;i++){
        if(curr_sum==0) tempStart=i;
        curr_sum+=nums[i];
        if(curr_sum>max_sum){
            max_sum=curr_sum;
            startIdx=tempStart;
            endIdx=i;
        }
        if(curr_sum<0){                                                                                                                                                                                                                                                                                                                                                                                                                          
            curr_sum=0;
        }
    }
    // Printing the sub Array 
    for(int i=startIdx;i<=endIdx;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return max_sum;
}
int main()
{
    vector<int>nums={-2,-3,4,-1,-2,1,5,-3};
    // int ans = INT_MIN;
    // PrintSubArr(nums,ans);
    // cout<<ans<<endl;
    cout<<MaxSubArrSum2(nums)<<endl;
    return 0;
}