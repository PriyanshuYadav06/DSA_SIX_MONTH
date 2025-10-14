#include<iostream>
using namespace std;
void solve(int op,int cl,string valid){
    // Base Case
    if(op==0 && cl==0){
        cout<<valid<<endl;
        return;
    }
    if(op>0){
        solve(op-1,cl,valid+"(");
    }
    if(cl>op){
        solve(op,cl-1,valid+")");
    }
}
int main(){
    int n=3;
    solve(n,n,"");
    return 0;
}