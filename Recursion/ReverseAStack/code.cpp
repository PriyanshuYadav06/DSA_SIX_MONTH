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
void insert(stack<int>&x,int lastEl){
    // Base Case
    if (x.empty()){
        x.push(lastEl);
        return;
    }
   int topEl=x.top();
   x.pop();
   insert(x,lastEl);
   // Induction
   x.push(topEl);
}
void reverse(stack<int>&x){
    int n=x.size();
    // Base Case
    if(n==1) return;
    // Hypothesis
    int topEl=x.top();
    x.pop();
    reverse(x);
    // Induction
    insert(x,topEl);
}
int main(){
    stack<int>x;
    x.push(50);
    x.push(40);
    x.push(30);
    x.push(20);
    x.push(10);
    display(x);
    reverse(x);
    display(x);
    return 0;
}