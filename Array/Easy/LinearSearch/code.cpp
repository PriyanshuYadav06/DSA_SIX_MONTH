#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int linearSearch(vector<int> &nums, int target)
{
    // your code goes here
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
            return i;
    }

    return -1;
}
int main()
{
    vector<int> nums = {2, 3, 4, 5, 3};
    cout << linearSearch(nums, 3) << endl;
    return 0;
}