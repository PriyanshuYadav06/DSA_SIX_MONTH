#include <iostream>
#include <vector>
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
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> curr;
    GenerateSubSets(nums, curr, 0, ans);
    return ans;
}
int main()
{
    vector<int>nums={1,2,3};
    vector<vector<int>> ans =subsets(nums);
    for(int i=0;i<ans.size();i++){
        display(ans[i]);
    }
    return 0;
}