#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void display(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
// This Works Good But there is no need t use of priority queue
vector<int> leaders(vector<int> &nums)
{
    int n = nums.size();
    priority_queue<int> maxhp;
    vector<int> leds;
    maxhp.push(nums[n - 1]);
    leds.push_back(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (!maxhp.empty())
        {
            int top = maxhp.top();
            if (nums[i] > top)
            {
                leds.push_back(nums[i]);
                maxhp.push(nums[i]);
            }
        }
    }
    return leds;
}
// Optimized Version Without          
vector<int>OptimizedLead(vector<int>&nums){
    int n=nums.size();
    int maxEl=INT_MIN;
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        if(ans.empty()){
            ans.push_back(nums[i]);
            maxEl=nums[i];
        }
        else{
            if(nums[i]>maxEl){
                ans.push_back(nums[i]);
                maxEl=nums[i];
            }
        }
    }
    return ans;
}                           
int main()
{
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> ans = OptimizedLead(nums);
    display(ans);
    return 0;
}