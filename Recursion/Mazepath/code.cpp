/*1.Grid Size : You are given a grid, typically of size M×N.The example shows a 3×3 grid.
2.Starting Point : You start at coordinate(0, 0).
3.Ending Point : Your goal is to reach coordinate(M−1, N−1).
4.Allowed Moves : From any given cell, you can only move Right or Down.
5.The main goal is usually one of two things:
*Count the total number of unique paths.
*Print all the unique paths as strings (e.g., "DDRR" for Down-Down-Right-Right).*/

#include <iostream>
using namespace std;
int mazePath(int cr, int cc, int er, int ec)
{
    // Base Case found one Path
    if (cr == er && cc == ec)
    {
        return 1;
    }
    int rightWays, downWays;
    if (cc != ec)
    {
        rightWays = mazePath(cr, cc + 1, er, ec);
    }
    else
    {
        rightWays = 0;
    }
    if (cr != er)
    {
        downWays = mazePath(cr + 1, cc, er, ec);
    }
    else
    {
        downWays = 0;
    }
    int totalWays = rightWays + downWays;
    return totalWays;
}
void printMazePath(int cr, int cc, int er, int ec, string path)
{
    // Failure Base Case: If we are out of bounds, stop this path.
    if (cr > er || cc > ec)
        return;
    // Success Base Case: If we are at the destination, print and stop this path.
    if (cr == er && cc == ec)
    {
        cout << path << endl;
        return;
    }
    // Recursive Step: Explore both possible moves.
    // The failure base case above will handle any invalid moves automatically.

    // 1. Move Right
    printMazePath(cr, cc + 1, er, ec, path + "R");
    // 2. Move Down
    printMazePath(cr + 1, cc, er, ec, path + "D");
}
int main()
{
    string str = "";
    printMazePath(1, 1, 4, 4, str);
    return 0;
}
