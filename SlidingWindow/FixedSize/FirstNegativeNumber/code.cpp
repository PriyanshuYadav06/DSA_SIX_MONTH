// First Negative Number in every Window of Size K
#include<iostream>
#include<vector>
using namespace std;
void FirstNegative(vector<int>nums,int k){
    int n=nums.size();
    vector<int>v;
    int i=0;
    int j=0;
    while(j<n){
        if(nums[j]<0){
            v.push_back(nums[j]);
        }
        if(j-i+1<k) j++;
        else if(j-i+1==k){
            if(v.empty()){
                cout<<0<<' ';
            }else{
                cout<<v.front()<<" ";
            }
            if(v.front()==nums[i]){
                v.erase(v.begin());
            }
            i++;
            j++;
        }
    } 

}
int main(){
    vector<int>nums={12,-1,-7,8,-15,30, 16, 28};
    FirstNegative(nums,3);
    return 0;
}