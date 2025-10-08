#include <iostream>
using namespace std;
int Power(int base, int power)
{
    if (power == 0) // 2,3(8) -> 2,2(4) -> 2,1(2) -> 2,0(1)
        return 1;

    return base * Power(base, power - 1);
}

int OptimizedPower(int base, int power)
{
    if (power == 1)
        return base;
    int halfPower = OptimizedPower(base, power / 2);
    if (power % 2 == 0)
    {
        return halfPower * halfPower;
    }
    else
    {
        return halfPower * halfPower * base;
    }
}
int main()
{

    cout << OptimizedPower(2, 3);
    return 0;
}