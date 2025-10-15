#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int SeclargestElement(vector<int> &nums)
{
    int max = INT_MIN;
    int idx = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
            idx = i;
        }
    }
    max = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == idx)
            continue;
        if (max < nums[i])
        {
            max = nums[i];
        }
    }
    return max;
}
int main()
{
    vector<int> nums = {3, 3, 6, 1, 7};
    cout << SeclargestElement(nums) << endl;
    return 0;
}