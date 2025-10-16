#include <iostream>
#include <vector>
using namespace std;
// Leetcode -> 2149
void display(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> x1;
    vector<int> x2;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            x1.push_back(nums[i]);
        else
            x2.push_back(nums[i]);
    }
    vector<int> ans;
    int i = 0;
    while (i < n / 2)
    {
        ans.push_back(x1[i]);
        ans.push_back(x2[i]);
        i++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = rearrangeArray(nums);
    // display(ans);
    return 0;
}