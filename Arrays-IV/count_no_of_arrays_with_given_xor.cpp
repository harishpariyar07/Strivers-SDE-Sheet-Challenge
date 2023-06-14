#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int, int> mp;
    mp[0] = 1;
    int prefXOR = 0, res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        prefXOR ^= arr[i];
        if (mp[prefXOR ^ x])
            res += mp[prefXOR ^ x];
        mp[prefXOR]++;
    }

    return res;
}