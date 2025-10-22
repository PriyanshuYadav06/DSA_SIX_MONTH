#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Leetcode -> 31
int main()
{
    vector<int> nums = {1, 2, 3};
    int n = nums.size();
    int idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        reverse(nums.begin(), nums.end());
        return 0;
    }
    else
    {
        for (int i = n - 1; i > idx; i--)
        {
            if (nums[i] > nums[idx])
            {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        reverse(nums.begin() + idx + 1, nums.end());
    }
    for (auto num : nums)
    {
        cout << num << " ";
    }
    return 0;
}