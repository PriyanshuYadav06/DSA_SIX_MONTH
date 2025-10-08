#include <iostream>
using namespace std;
int fact(int num)
{
    // Base Case
    if (num == 0 || num == 1)
        return 1;
    return num * fact(num - 1);
}
int main()
{
    int num = 5;
    cout << "Factorial of " << num << ":" << fact(num) << endl;
    return 0;
}