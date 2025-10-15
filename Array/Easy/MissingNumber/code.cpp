#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
            return i;
    }
    return n;
}
int main()
{
    vector<int> nums = {3, 0, 1};
    cout<<missingNumber(nums)<<endl;

    return 0;
}