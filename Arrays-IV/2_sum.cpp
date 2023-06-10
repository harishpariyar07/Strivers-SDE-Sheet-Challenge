// Two sum problem with all the pairs with given sum
// Extra O(N) space complexity for map
// Extra O(NlogN) time complexity for sorting resultant pairs

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    vector<vector<int>> res;
    unordered_map<int, int> mp;
    for (auto i : arr)
    {
        int rem = s - i;
        if (mp[rem])
        {
            int k = mp[rem];
            while (k--)
            {
                res.push_back({min(i, rem), max(i, rem)});
            }
        }
        mp[i]++;
    }
    sort(res.begin(), res.end());
    return res;
}