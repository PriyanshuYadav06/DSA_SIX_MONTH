#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Leetcode -> 485
// Brute Force Solution
int findMaxConsecutiveOnes1(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] == 1)
            {
                count++;
                if (j == n - 1)
                {
                    maxi = max(count, maxi);
                    break;
                }
            }
            else
            {
                maxi = max(count, maxi);
                break;
            }
        }
    }
    return maxi;
}
// Optimized 
int findMaxConsecutiveOnes2(vector<int> &nums)
{
    int n = nums.size();
    int count =0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            count++;
        }else{
            maxi=max(maxi,count);
            count=0;
        }
    }
    return max(maxi,count);
}
int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout<<findMaxConsecutiveOnes2(nums)<<endl;
    return 0;
}