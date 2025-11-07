#include <iostream>
#include <vector>
using namespace std;
// LeeCode -> 238
void display(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}
// Brute Force
// vector<int> productExceptSelf(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         int temp = 1;
//         for (int j = 0; j < n; j++)
//         {
//             if (i == j)
//                 continue;
//             temp *= nums[j];
//         }
//         ans.push_back(temp);
//     }
//     return ans;
// }
// Using Prefix and Suffix Array
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int>preffix(n);
    vector<int>suffix(n);
    vector<int>ans;
    preffix[0]=nums[0];
    suffix[n-1]=nums[n-1];
    for(int i=1;i<n;i++){
        preffix[i]=preffix[i-1]*nums[i];
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*nums[i];
    }
    for(int i=0;i<n;i++){
        ans.push_back(preffix[i - 1] * suffix[i + 1]);
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);
    display(ans);
    return 0;
}