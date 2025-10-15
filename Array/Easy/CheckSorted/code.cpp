#include <iostream>
#include <vector>
using namespace std;
// LeetCode-> 1752
// Hint-> If the array is a rotated sorted array, there should be at most one place where nums[i] > nums[i+1].
bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
            count++;
        if (count > 1)
            return false;
    }
    return true;
}
int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    cout<<check(nums)<<endl;
    return 0;
}