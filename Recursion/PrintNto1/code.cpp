#include <iostream>
using namespace std;
void PrintIncreasing(int num)
{
    // Base Case
    if (num == 0)
        return;
    // Inductio
    cout << num << " ";
    // Hypothesis
    PrintIncreasing(num - 1);
}
void PrintDecreasing(int num)
{
    // Base Case
    if (num == 0)
        return;
    // Hypothesis
    PrintDecreasing(num - 1);
    // Insduction Step
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