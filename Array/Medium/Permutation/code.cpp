#include <iostream>
#include <vector>
using namespace std;
// Leetcode -> 46
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<endl<<endl;
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
    vector<vector<int>> ans;
    permute(nums, 0, ans);
    printMatrix(ans);
    return 0;
}