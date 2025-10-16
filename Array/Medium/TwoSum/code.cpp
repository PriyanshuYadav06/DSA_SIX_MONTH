#include <iostream>
#include<unordered_map>
#include <vector>
using namespace std;
// Leetcode -> 1
// This is O(n^2) Solution not optimized
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}
// Optimized Solution
vector<int> OptimizeTwoSum(vector<int>&nums,int target){
    int n = nums.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int compliment= target-nums[i];
        if(mp.find(compliment)!=mp.end()){
            return {mp[compliment],i};
        }
        mp[nums[i]]=i;
    }
    return {};
} 

int main()
{
    vector<int>nums={2,7,11,15};
    vector<int>ans=OptimizeTwoSum(nums,9);
    for(int x : ans){
        cout<<x<<" ";
    }
    return 0;
}