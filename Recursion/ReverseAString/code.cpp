#include <iostream>
using namespace std;
string reverse(string str,int n){
    // Base Case
    if(n==1) return str;
    // Hypothesis
    char lastChar = str.back();
    str.pop_back();
    // Induction
    return lastChar+reverse(str,n-1);
}
int main()
{
    string str="ABCDE";
    int n=str.size();
    cout<<reverse(str,n);
    return 0;
}