// Longest consecutive sequence
// O(N) TC and O(N) SC
// Store each unique element in the set
// Traverse again and find the max range starting from the least element of any valid range

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{
    unordered_map<int, int> mp;
    int sum = 0, res = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            res = i + 1;
        }
        else
        {
            if (mp.find(sum) != mp.end())
            {
                res = max(res, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }

    return res;
}