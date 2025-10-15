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
vector<int> unionArray1(vector<int> &nums1, vector<int> &nums2)
{
    set<int> s;
    for (int num : nums1)
    {
        s.insert(num);
    }
    for (int num : nums2)
    {
        s.insert(num);
    }
    vector<int> ans;
    for (int num : s)
    {
        ans.push_back(num);
    }
    return ans;
}
vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ans;
    int n = nums1.size();
    int m = nums2.size();
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (nums1[i] == nums2[j])
        {
            if (ans.empty() || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] > nums2[j])
        {
            if (ans.empty() || ans.back() != nums2[j])
            {
                ans.push_back(nums2[j]);
            }
            j++;
        }
        else
        {
            if (ans.empty() || ans.back() != nums1[i])
            {
                ans.push_back(nums1[i]);
            }
            i++;
        }
    }
    if (i == n)
    {
        while (j < m)
        {
            if (ans.empty() || ans.back() != nums2[j])
                ans.push_back(nums2[j]);
            j++;
        }
    }
    if (j == m)
    {
        while (i < n)
        {
            if (ans.empty() || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums1 = {3, 4, 6, 7, 9, 9};
    vector<int> nums2 = {1, 5, 7, 8, 8};
    vector<int> ans1 = unionArray1(nums1, nums2);
    vector<int> ans2 = unionArray(nums1, nums2);

    cout << "Using set-based union: ";
    display(ans1);

    cout << "Using two-pointer merge: ";
    display(ans2);
    return 0;
}