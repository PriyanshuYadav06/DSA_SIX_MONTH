#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}
// Prefix Sum
vector<int> prefixSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    ans[0]=nums[0];
    for (int i = 1; i < n; i++)
    {
       ans[i]=ans[i-1]+nums[i];
    }
    return ans;
}
//Suffix Sum
vector<int> suffixSum(vector<int>&nums){
    int n=nums.size();
    vector<int>ans(n);
    ans[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--){
        ans[i]=ans[i+1]+nums[i];
    }
    return ans;
}

int main()
{
    vector<int> nums = {5,4,1,2,3};
    vector<int> ans = suffixSum(nums);
    display(ans);
    return 0;
}