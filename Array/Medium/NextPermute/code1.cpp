#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
// Leetcode -> 31
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<endl<<endl;
}
int FindNextPermute(vector<vector<int>>list, vector<int>nums){
    int idx=-1;
    int n= list.size();
    for(int i=0;i<n;i++){
        if(list[i]==nums){
            idx=i;
        }
    }
    if(idx==n-1)  return  0 ; else  return  idx;
}
void permute(vector<int> &nums, int idx, vector<vector<int>> &ans)
{

    int n = nums.size();
    if (idx == n)
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        swap(nums[idx], nums[i]);
        permute(nums, idx + 1, ans);
        // backtrack
        swap(nums[idx], nums[i]);
    }
}
int main()
{
    vector<int> nums = {3, 1, 2};
    vector<int>temp=nums;
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    permute(nums, 0, ans);
    int idx = FindNextPermute(ans,temp);
    // Printing the Next Permutaion
    for(int i=0;i<ans[idx].size();i++){
        cout<<ans[idx][i]<<" ";
    }
    return 0;
}