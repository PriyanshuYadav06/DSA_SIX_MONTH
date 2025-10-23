#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool BinarySearch(vector<int> v, int target)
{
    int n = v.size();
    sort(v.begin(),v.end());
    int lo=0;
    int hi =n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]==target) return true;
        else if(v[mid]<target) lo=mid+1;
        else hi=mid-1; 
    }
    return false;
}
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        int x = nums[i];
        int count=1;
        while(BinarySearch(nums,x+1)){
            count++;
            x++;
        }
        maxi=max(count,maxi);
    }
    return maxi;
}
int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int n = nums.size();
    cout << longestConsecutive(nums) << endl;
    return 0;
}