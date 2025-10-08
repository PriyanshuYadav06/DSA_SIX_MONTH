#include <iostream>
using namespace std;
string Reverse(string str, int n)
{
    if (n == 0)
        return "";
    return str[n - 1] + Reverse(str, n - 1);
}

int main()
{
    string str;
    cout << Reverse("Priyanshu", 9) << endl;
    return 0;
}