
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// Leetcode -> 73
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<endl<<endl;
}
void help(vector<vector<int>> &matrix, pair<int, int> x)
{
    int r = matrix.size();
    int c = matrix[0].size();
    for (int m = 0; m < r; m++)
    {
        matrix[m][x.second] = 0;
    }
    for (int m = 0; m < c; m++)
    {
        matrix[x.first][m] = 0;
    }
}
void setZeroes(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    vector<pair<int, int>> vec;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
                vec.push_back({i, j});
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        help(matrix, vec[i]);
    }
}
int main()
{
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    printMatrix(matrix);
    setZeroes(matrix);
    printMatrix(matrix);
    return 0;
}