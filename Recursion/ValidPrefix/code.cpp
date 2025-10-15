#include <iostream>
#include<vector>
#include <cctype>
#include <set>
using namespace std;
bool validPrefix(string str){
    int co=0;
    int cz=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='0') cz++;
        else co++;
    }
    return co>cz;
}
void GeneratePrefix(string str,  vector<string>&ans){
    for(int i=0;i<=str.length();i++){
       if(validPrefix(str.substr(0,i))){
        ans.push_back(str.substr(0,i));
       }
    }
}
int main()
{
    vector<string>ans;
    GeneratePrefix("100",ans);
    for(auto x : ans){
        cout<<x<<endl;
    }
    return 0;
}