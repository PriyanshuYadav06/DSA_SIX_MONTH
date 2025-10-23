#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    for (int num : s)
    {
        // Check if this number could be the start of a sequence
        if (s.find(num - 1) == s.end())
        {
            int currentNumber = num;
            int streak = 1;

            // Count forward while the next number exists
            while (s.find(currentNumber + 1) != s.end())
            {
                streak++;
                currentNumber++;
            }
            longest = max(longest, streak);
        }
    }
    return longest;
}
int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int n = nums.size();
    cout << longestConsecutive(nums) << endl;

    return 0;
}