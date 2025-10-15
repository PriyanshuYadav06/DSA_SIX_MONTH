#include <iostream>
#include<vector>
#include <cctype>
#include <set>
using namespace std;
int josephus(int n, int k){
    // Base Case
    if(n==1){
        return 0;
    }

    return (josephus(n-1,k)+k)%n;
}
int main()
{
    cout << "Happy 6th Commit" << endl;
    cout<<josephus(5,2)+1;
    return 0;
}