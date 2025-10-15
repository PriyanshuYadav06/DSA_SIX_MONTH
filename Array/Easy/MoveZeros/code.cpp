#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
// LeetCode -> 283
void display(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=0){
            nums[i]=nums[j];
            i++;
        }
       
        }
         while(i<n){
            nums[i]=0;
            i++;
        }
    }
int main()
{
    vector<int>nums={0,0,1,1,1,2,2,3,3,4};
    display(nums);
    moveZeroes(nums);
    display(nums);
    return 0;
}