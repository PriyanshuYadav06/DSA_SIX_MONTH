#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    sort(nums.begin(), nums.end());
    int count = 1;
    int maxi = 1;
    int prevNum = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == prevNum)
        {
            // Duplicate, just continue
            continue;
        }
        else if (nums[i] == prevNum + 1)
        {
            // Consecutive number
            count++;
        }
        else
        {
            // Not consecutive, reset count
            maxi = max(maxi, count);
            count = 1;
        }
        prevNum = nums[i];
    }

    return max(maxi, count);
}
int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int n = nums.size();
    cout << longestConsecutive(nums) << endl;

    return 0;
}