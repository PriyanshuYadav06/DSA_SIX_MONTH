#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// 1. Generate all subsequences (recursive copy version)
void generateSubsequencesCopy(string str, string curr)
{
    // Base Case
    if (str.length() == 0)
    {
        cout << curr << endl;
        return;
    }
    string op1 = curr;
    string op2 = curr;
    op2.push_back(str[0]);
    str.erase(str.begin() + 0);
    // exclude the first char
    generateSubsequencesCopy(str, op1);
    // include the first char
    generateSubsequencesCopy(str, op2);
}
// 2. Generate all subsequences using index
void generateSubsequencesIndex(string ip, string op, int index, vector<string> &ans)
{
    if (index == ip.length())
    {
        ans.push_back(op);
        return;
    }
    // exclude the first char
    generateSubsequencesIndex(ip, op, index + 1, ans);
    // include the first char
    generateSubsequencesIndex(ip, op + ip[index], index + 1, ans);
}
// 3. Generate only unique subsequences
void generateUniqueSubsequences(string ip, string op, int idx, set<string> &ans)
{
    // Base Case
    if (ip.length() == idx)
    {
        ans.insert(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[idx]);
    generateUniqueSubsequences(ip, op1, idx + 1, ans);
    generateUniqueSubsequences(ip, op2, idx + 1, ans);
}
// 4. Generate subsequences with spaces inserted between characters
void generateSubSeqWithSpace(string ip, string op, int idx)
{
    // Base Case
    if (ip.length() == idx)
    {
        cout<<"[";
        cout << op;
        cout<<"]";
        return;
    }
    string op1 = op;
    string op2 = op;
    if (idx == 0)
    {
        generateSubSeqWithSpace(ip, op + ip[idx], idx + 1);
    }
    else
    {
        op1.push_back(' ');
        op1.push_back(ip[idx]);
        op2.push_back(ip[idx]);
        generateSubSeqWithSpace(ip, op1, idx + 1);
        generateSubSeqWithSpace(ip, op2, idx + 1);
    }
}
// 5. Generate all case variations (a → a or A)
void generateCasePermutations(string ip,string op,int idx){
    // Base Case
    if (idx == ip.length()) {
        cout << "[" << op << "] ";
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back(tolower(ip[idx]));
    op2.push_back(toupper(ip[idx]));
    generateCasePermutations(ip,op1,idx+1);
    generateCasePermutations(ip,op2,idx+1);
}


// 6. Generate all case variations (a → a or A) including digits
void generateCaseVariations(string ip, string op, int idx)
{
    // Base Case
    if (idx == ip.length())
    {
        cout << "[" << op << "] ";
        return;
    }

    if (isalpha(ip[idx]))
    {
        string op1 = op;
        string op2 = op;
        op1.push_back(tolower(ip[idx]));
        op2.push_back(toupper(ip[idx]));
        generateCaseVariations(ip, op1, idx + 1);
        generateCaseVariations(ip, op2, idx + 1);
    }
    else
    {
        string op1 = op;
        op1.push_back(ip[idx]);
        generateCaseVariations(ip, op1, idx + 1);
    }
}
int main()
{
    string str = "abc";
    set<string> ans;
    vector<string> allSubseq;
    // Print all SubSeq in LexoGraphicall
    // generateSubsequencesIndex(str, "", 0, allSubseq);
    // sort(allSubseq.begin(), allSubseq.end());
    // for (auto x : allSubseq)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    // Print All Unique Subseq
    // generateUniqueSubsequences(str, "", 0, ans);
    // for (auto x : ans)
    // {
    //     cout << x << " ";
    // }
    // Permutaion With spaces
    generateSubsequencesCopy(str, "");
    return 0;
}