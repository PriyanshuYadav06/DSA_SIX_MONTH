// A person is standing on the ground and wants to climb to the nth stair.The person can take either a singlestep(climb one stair) or a double step(climb two stairs) at a time.

// The  question is to find the total number of distinct ways the person can reach the nth stair.
#include <iostream>
using namespace std;
int NumberOfWaysOne(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    else
        return NumberOfWaysOne(n - 1) + NumberOfWaysOne(n - 2);
}
/*If The person can take a single step(climb 1 stair), a double step(climb 2 stairs), or a triple step(climb 3 stairs) at a time.*/

int NumberOfWaysTwo(int n)
{
    if (n == 1 || n == 2)
        return n;
    if (n == 3)
        return 4;
    else
        return NumberOfWaysTwo(n - 1) + NumberOfWaysTwo(n - 2) + NumberOfWaysTwo(n - 3);
}

int main()
{
    int n;
    cout << "Enter number of staris:";
    cin >> n;
    cout << NumberOfWaysOne(n) << endl;
    cout << NumberOfWaysTwo(n) << endl;
    return 0;
}