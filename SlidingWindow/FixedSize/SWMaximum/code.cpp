#include<iostream>
#include <map>
#include<vector>
#include <deque>
#include<climits>
using namespace std;
// Leetcode -> 239
void Display(vector<int>v){
    int n= v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
// Not efficient way 
void MaxOfAllSubArray1(vector<int>nums,vector<int>&ans,int k){
   int n = nums.size();
   int i=0, j=0;
   int maxi=INT_MIN;
   while(j<n){
     maxi = max(maxi, nums[j]);
     if(j-i+1<k) j++;
     else if(j-i+1==k){
        ans.push_back(maxi);
        if (nums[i] == maxi) {
            maxi = INT_MIN;
            for (int p = i + 1; p <= j; p++)
                maxi = max(maxi, nums[p]);
        }
        i++;
        j++;
     }
   }
}
//Optimized One
void maxSlidingWindow(vector<int>& nums,vector<int>& ans, int k) {
    int n = nums.size();
    deque<int> dq; // store indices
    int i = 0, j = 0;

    while (j < n) {
        // maintain decreasing order in deque
        while (!dq.empty() && nums[dq.back()] < nums[j])
            dq.pop_back();

        dq.push_back(j);

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k) {
            ans.push_back(nums[dq.front()]); // current max

            // remove index if it is leaving the window
            if (dq.front() == i)
                dq.pop_front();

            i++;
            j++;
        }
    }
}

int main(){
    vector<int>nums={9,11};
    int k=2;
    vector<int>ans;
    maxSlidingWindow(nums,ans,k);
    Display(ans);
    return 0;
}