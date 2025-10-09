#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
/*void InsertIterative(vector<int> &arr){
    int n=arr.size();
    int lastEl=arr[n-1];
    int j=n-1;
    while(j>=1){
        if(arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
        }else{
            break;
        }
        j--;
    }
    return;
}*/
void InsertRec(vector<int>&arr,int lastEl){
    int n= arr.size();
    // Base Case
    if(n==0 || arr[n-1]<=lastEl){
        arr.push_back(lastEl);
        return;
    }
    int maxEl=arr[n-1];
    arr.pop_back();
    InsertRec(arr,lastEl);
    arr.push_back(maxEl);
}
void Sort(vector<int> &arr)
{
    // Base Case
    int n=arr.size();
    if(n==1) return;
    int lastEl=arr[n-1];
    arr.pop_back();
    // Hypothesis
    Sort(arr);
    // Induction
    InsertRec(arr,lastEl);
}

int main()
{
    vector<int> arr = {2, 4,45,1,50,5, 6, 8, 3};
    int n = arr.size();
    display(arr);
    Sort(arr);
    display(arr);
    return 0;
}