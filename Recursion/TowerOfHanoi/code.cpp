#include <iostream>
#include <cmath>
using namespace std;
void Min_Move_TowerOfHanoi(int n)
{
    cout << pow(2, n) - 1 << endl;
}
void towerOfHanoi(int n, string src, string helper, string dest)
{
    // Base case
    if (n == 0)
        return;
    // Step 1: Move (n-1) disks from source to helper using destination as temporary
    towerOfHanoi(n - 1, src, dest, helper);
    // Step 2: Move the largest disk from source to destination
    cout << src << "->" << dest << endl;
    // Step 3: Move (n-1) disks from helper to destination using source as temporary
    towerOfHanoi(n - 1, helper, src, dest);
    return;
}
int main()
{
    Min_Move_TowerOfHanoi(5);
    int n = 3;                      // Number of disks
    towerOfHanoi(n, "A", "B", "C"); // Solve the problem
    return 0;
}
