#include <iostream>
using namespace std;
// Most Important logic Also Build the foundation of Eular Tree
// Same question Print ZigZag'
// n=2, o/p-> 211121112
void PreInPost(int n)
{
    if (n == 0)
        return;
    cout << "Pre:" << n << endl;
    PreInPost(n - 1);
    cout << "In" << n << endl;
    PreInPost(n - 1);
    cout << "Post" << n << endl;
}
int main()
{
    PreInPost(4);
    return 0;
}