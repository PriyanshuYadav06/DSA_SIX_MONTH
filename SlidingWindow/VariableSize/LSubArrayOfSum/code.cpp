#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <climits>
using namespace std;
// Leetcode -> 239
void Display(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
// its only works for +Ve Number
void LSubArrayOfSum(vector<int> nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int maxi=0;
    while (j < n)
    {
        sum += nums[j];
        if (sum <k) j++;
        else if(sum>k){
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            j++;
        }
        else if(sum==k){
            maxi=max(maxi,j-i+1);
            j++;
        }
        
    }
    cout<<maxi<<endl;
}
int main()
{
    vector<int> nums = { 1, 2,1,2,1};
    int k = 3;
    vector<int> ans;
    LSubArrayOfSum(nums, k);
    Display(ans);
    return 0;
}