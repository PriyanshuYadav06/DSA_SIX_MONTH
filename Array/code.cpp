#include <iostream>
#include <vector>
using namespace std;
// Leetcode -> 121
void print(int st,int en,vector<int> &nums){
    for(int i=st;i<=en;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
void PrintSubArr(vector<int> &nums)
{
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            print(i,j,nums);
        }
    }
}
int main()
{
    vector<int>nums={1,2,3,4,5};
    PrintSubArr(nums);
    return 0;
}