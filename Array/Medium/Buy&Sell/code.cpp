#include <iostream>
#include <vector>
using namespace std;
// Leetcode -> 121
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // Keep track of the minimum price so far
        mini = min(mini, prices[i]);
        // Update max profit if today's profit is better
        maxi = max(maxi, prices[i] - mini);
    }
    return maxi;
}
int main()
{
    vector<int>prices={7,1,5,3,6,4};
    cout<<maxProfit(prices);

    return 0;
}