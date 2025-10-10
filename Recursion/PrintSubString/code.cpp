#include<iostream>
using namespace std;
// This is Working but the better and efficient solution is using indexing
void subString1(string str,string curr){
    // Base Case
    if(str.length()==0){
        cout<<curr<<endl;
        return;
    }
    string op1=curr;
    string op2=curr;
    op2.push_back(str[0]);
    str.erase(str.begin()+0);  
    // exclude the first char
    subString1(str,op1);
    // include the first char
    subString1(str,op2);
}
// The Solution with Indexing 
void subString2(string ip,string op, int index){
        if (index == ip.length()) {
        cout << op << endl;
        return;
    }
    // exclude the first char
    subString2(ip,op,index+1);
    // include the first char
    subString2(ip,op+ip[index],index+1);
}
int main(){
    string str="priyanshu";
    // subString1(str,"");
    subString2(str,"",0);
    return 0;
}