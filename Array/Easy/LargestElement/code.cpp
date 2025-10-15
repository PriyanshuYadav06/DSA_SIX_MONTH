#include<iostream>
#include<vector>
#include<climits>
using namespace std;
  int largestElement(vector<int>& nums) {
        int max = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(max<nums[i]){
                max=nums[i];
            }
        }
        return max;
    }
int main(){
    vector<int> nums={3,3,6,1};
    cout<<largestElement(nums)<<endl;
    return 0;
}