#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
// LeetCode -> 26
void display(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
int main()
{
    vector<int>nums={0,0,1,1,1,2,2,3,3,4};
    display(nums);
    cout<<removeDuplicates(nums)<<endl;
    display(nums);
    return 0;
}