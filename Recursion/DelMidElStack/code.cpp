#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void display(stack<int>s){
    vector<int>temp;
    while(!s.empty()){
        temp.push_back(s.top());
        s.pop();
    }
    for(int i=temp.size()-1;i>=0;i--){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
void DelMidEL(stack<int>&x,int k){
    // Base Case
    if(k==1){
        x.pop();
        return;
    }
    //Hypothesis
    int topEl=x.top();
    x.pop();
    DelMidEL(x,k-1);
    // Induction 
    x.push(topEl);
}
int main(){ 
    stack<int>x;
    x.push(15);
    int k=(x.size()/2)+1;
    display(x);
    DelMidEL(x,k);
    display(x);
    return 0;
}