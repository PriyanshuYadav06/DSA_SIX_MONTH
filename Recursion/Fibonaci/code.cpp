#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> x)
{
    cout << x.size() << endl;
    for (int i = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << endl;
}
void FibonacciSeries(int num)
{
    vector<int> digits;
    digits.push_back(0);
    digits.push_back(1);
    int curr = 0;
    int prev = 1;
    int next = curr + prev;
    for (int i = 2; i < num; i++)
    {
        digits.push_back(next);
        curr = digits[digits.size() - 1];
        prev = digits[digits.size() - 2];
        next = curr + prev;
    }
    display(digits);
}
int NthFibonaci(int num)
{
    if (num == 1)
        return 0;
    if (num == 2)
        return 1;
    int curr = 1;
    int prev = 0;
    int next = curr + prev;
    for (int i = 2; i < num; i++)
    {
        prev = curr;
        curr = next;
        next = curr + prev;
    }
    return curr;
}
int Fibonacci_Rec(int num)
{
    if (num == 1)
        return 0;
    if (num == 2)
        return 1;
    return Fibonacci_Rec(num - 1) + Fibonacci_Rec(num - 2);
}
int main()
{
    int x;
    cout << "Enter a number:";
    cin >> x;
    cout << Fibonacci_Rec(x);
}