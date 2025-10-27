#include<iostream>
#include <map>
#include<vector>
using namespace std;
void CountAnagrams(string s1,string s2){
    int n = s1.size();
    int k = s2.size();
    map<char,int>mp;
    for (char c : s2)
        mp[c]++;
         int count = mp.size();
    int i=0;
    int j=0;
    int ans = 0;
    while(j<n){
        if(mp.find(s1[j])!=mp.end()){
            mp[s1[j]]--;
            if(mp[s1[j]]==0)
            count--;
        }
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(count ==0) ans++;
            // Just Reverse The Work
            if(mp.find(s1[i])!=mp.end()){
                if(mp[s1[i]]==0) count++;
                mp[s1[i]]++;
            }

            i++;
            j++;
        }
    }
    cout << "Total Anagrams: " << ans << endl;

}
int main(){
    CountAnagrams("aabaabaa","aaba");
    return 0;
}