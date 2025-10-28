#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <set>
#include <unordered_map>
#include <climits>
using namespace std;
// Leetcode -> 239
void Display(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
// its only works for +Ve Number
void LSubStringKUnique(string str, int k)
{
    int n = str.size();
    int i = 0;
    int j = 0;
    unordered_map<char, int> mp;
    int maxi = 0;
    while (j < n)
    {
        mp[str[j]]++;
        if (mp.size() < k)
            j++;
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                {
                    mp.erase(str[i]);
                }
                i++;
            }
        }
        else if (mp.size() == k)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }
    }
    cout << maxi << endl;
}
int main()
{
    string str = "aaaa";
    int k = 3;
    LSubStringKUnique(str, k);
    return 0;
}