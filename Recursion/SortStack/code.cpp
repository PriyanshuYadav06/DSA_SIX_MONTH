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
    int n=x.size();
    // Base Case
    if(n==0 || x.top()<=lastEl){
        x.push(lastEl);
        return;
    }
    int maxEl=x.top();
    x.pop();
    insert(x,lastEl);
    x.push(maxEl);

}
void sort(stack<int>&x){
    int n=x.size();
    // Base Case
    if(n==1) return;
    // Hypothesis
    int lastEl=x.top();
    x.pop();
    sort(x);
    // Induction
    insert(x,lastEl);
}
int main(){
    stack<int>x;
    x.push(50);
    x.push(40);
    x.push(30);
    x.push(20);
    x.push(10);
    display(x);
    sort(x);
    display(x);
    return 0;
}