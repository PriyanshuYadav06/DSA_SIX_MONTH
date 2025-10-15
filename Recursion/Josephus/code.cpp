#include <iostream>
#include<vector>
#include <cctype>
#include <set>
using namespace std;
int josephus(int n, int k){
    // Base Case
    // If there is only one person, they are the survivor (index 0 in 0-based indexing)
    if(n==1){
        return 0;
    }
    // josephus(n - 1, k) returns the safe position in a smaller circle (with n-1 people)
    // Adding k shifts the safe position forward by k steps, as we eliminate every k-th person
    // The modulo operator (%) wraps the position around the circle when it goes beyond n
    return (josephus(n-1,k)+k)%n;
}
int main()
{
    cout<<josephus(40,7)+1<<endl;
    return 0;
}