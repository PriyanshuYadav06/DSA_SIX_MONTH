#include <iostream>
#include <vector>
using namespace std;
// Leetcode -> 118;
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
long long PascalVal(int r, int c)
{
    long long res = 1;
    for (int i = 1; i <= c; i++)
    {
        res = res * (r - i + 1) / i;
    }
    return res;
}
void NthRow(int n, vector<vector<int>> &ans)
{
    vector<int> r;
    for (int i = 1; i <= n; i++)
    {
        r.push_back(PascalVal(n - 1, i - 1));
    }
    ans.push_back(r);
}
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++)
    {
        NthRow(i, ans);
    }
    return ans;
}
int main()
{
    vector<vector<int>>ans;
    ans=generate(5);
    printMatrix(ans);
    return 0;
}