// In case of +ve and -ve numbers
// We have to use hashmap of prefix sum, we can't optimize it further
// Here, target = 0
// Replace 0 with target for target = k

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