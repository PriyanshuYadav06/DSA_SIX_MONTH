#include <iostream>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;
void display(vector<int> arr)
{
    cout<<"{";
    for (int i = 0; i < arr.size(); i++)
    {
        cout <<"["<< arr[i]<<"]" << " ";
    }
    cout <<"}"<<endl;
}
// Generate all subsets (including duplicates if input has duplicates)
void GenerateSubSets(vector<int> num, vector<int> &curr, int index, vector<vector<int>> &ans)
{
    int n = num.size();
    if (n == index)
    {
        ans.push_back(curr);
        return;
    }
    GenerateSubSets(num, curr, index + 1, ans);
    curr.push_back(num[index]);
    GenerateSubSets(num, curr, index + 1, ans);
    curr.pop_back(); // Backtrack after including num[index]
}
// Generate unique subsets using a set
void GenerateUniqueSubSets(vector<int> num, vector<int> &curr, int index, set<vector<int>> &ans)
{
    int n = num.size();
    if (n == index)
    {
        ans.insert(curr);
        return;
    }
    GenerateUniqueSubSets(num, curr, index + 1, ans);
    curr.push_back(num[index]);
    GenerateUniqueSubSets(num, curr, index + 1, ans);
    curr.pop_back(); // Backtrack after including num[index]
}
vector<vector<int>> Allsubsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> curr;
    GenerateSubSets(nums, curr, 0, ans);
    return ans;
}
void Uniquesubsets(vector<int> &nums)
{
    set<vector<int>>ans;
    vector<int> curr;
    sort(nums.begin(), nums.end()); // Sort for consistent ordering
    GenerateUniqueSubSets(nums, curr, 0, ans);
    for(auto x : ans){
        cout<<"{";
        for(auto y : x ){
           cout <<"["<<y<<"]" << " ";
        }
        cout<<"}"<<endl;
    }
}
int main()
{
    vector<int>nums={1,2,2};
    vector<vector<int>> ans =Allsubsets(nums);
    for(int i=0;i<ans.size();i++){
        display(ans[i]);
    }
    cout<<"Printing Unique Subsets...."<<endl;
    Uniquesubsets(nums);
    return 0;
}