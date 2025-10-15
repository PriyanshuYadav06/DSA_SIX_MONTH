#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void reverse(int st,int en,vector<int>&v){
    int i =st;
    int j=en;
    while(j>=i){
        swap(v[i],v[j]);
        i++;
        j--;
    }
}
void RotateByk(vector<int>&v,int k){
    int n = v.size();
    reverse(0,n-k-1,v);
    reverse(n-k,n-1,v);
    reverse(0,n-1,v);
}
int main(){
    vector<int>nums={3,4,5,1,2};
    int n=nums.size();
    int k=3;
    // this line is important for code optimization
    // It prevents unnecessary full rotations.
    if(k>n){
        k=k%n;
    }
    display(nums);
    RotateByk(nums,3);
    display(nums);
    return 0;
}