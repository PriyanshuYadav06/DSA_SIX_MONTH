
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int major = n / 2;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp.find(nums[i]) != mp.end())
        {
            if (mp[nums[i]] > n / 2)
                return nums[i];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<majorityElement(nums)<<endl;
    return 0;
}