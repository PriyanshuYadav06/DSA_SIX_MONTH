#include <iostream>
using namespace std;
void PrintIncreasing(int num)
{
    if (num == 0)
        return;
    cout << num << " ";
    PrintIncreasing(num - 1);
}
void PrintDecreasing(int num)
{
    if (num == 0)
        return;
    PrintDecreasing(num - 1);
    cout << num << " ";
}
int main()
{
    int num;
    cout << "Enter a Number:";
    cin >> num;
    PrintIncreasing(num);
    cout << endl;
    PrintDecreasing(num);
    return 0;
}