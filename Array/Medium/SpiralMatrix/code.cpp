#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Leetcode -> 54
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
void display(vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // initial row index
    int top = 0;
    // last row index
    int bottom = matrix.size() - 1;
    // initial column index
    int left = 0;
    // last column index
    int right = matrix[0].size() - 1;
    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        // Left to right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        // Top to bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        // Right to left (check if there's a row remaining)
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        // Bottom to top (check if there's a column remaining)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printMatrix(matrix);
    vector<int> ans = spiralOrder(matrix);
    display(ans);
    return 0;
}