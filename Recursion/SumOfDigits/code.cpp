#include <iostream>
using namespace std;
int SumOfDigits(int n)
{
    // Base Case
    if (n == 0)
        return 0;
    return n % 10 + SumOfDigits(n / 10);
}

int main()
{
    cout << SumOfDigits(134);
    return 0;
}