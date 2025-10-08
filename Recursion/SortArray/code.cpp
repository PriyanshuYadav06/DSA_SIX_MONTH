#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Insert(vector<int> &arr, int last)
{

    // 3 4 6
    int n = arr.size();

    if (n == 0 || arr[n - 1] <= last)
    {
        arr.push_back(last);
        return;
    }

    int lastEle = arr[n - 1];
    arr.pop_back();

    Insert(arr, last);
    arr.push_back(lastEle);
}
void Sort(vector<int> &arr, int n)
{
    // Base Case
    if (n == 0)
        return;

    int lastEle = arr[n - 1];

    Sort(arr, n - 1);
    Insert(arr, lastEle);
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    display(arr);
    Sort(arr, n);
    display(arr);

    return 0;
}