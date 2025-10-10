#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// There is Something Odd in This Logic , You Have to figure it out;
void deleteMidEl(vector<int>&arr,int k){
    int n=arr.size();
    // Base Case
    if(k==1){
        arr.pop_back();
        return;
    }
    // Hypothesis
    int lastEl=arr[n-1];
    arr.pop_back();
    deleteMidEl(arr,k-1);
    // Induction 
    arr.push_back(lastEl);


}
int main(){
    vector<int>arr ={1,2,3,4,5,6,7,8,9};
    int n= arr.size();
    int k=(n/2)+1;
    display(arr);
    // deleteMidEl(arr,k);
    Delete(arr,k);
    display(arr);
    return 0;
}