#include<iostream>
#include <map>
#include<vector>
using namespace std;
void Display(vector<int>v){
    int n= v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void MaxOfAllSubArray(vector<int>nums,vector<int>&ans,int k){
   int n = nums.size();
   int i=0;
   int j=0;
   int maxi=INT_MIN;
   while(j<n){
    if(maxi<nums[j]){
        maxi=nums[j];
    }
    if(j-i+1<k) j++;
    if(j-i+1==k){
        ans.push_back(maxi);
        i++;
        j++;
    }
   }
}
int main(){
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int>ans;
    MaxOfAllSubArray(nums,ans,k);
    Display(ans);
    return 0;
}