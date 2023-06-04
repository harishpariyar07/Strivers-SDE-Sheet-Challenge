#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> res;
    res.push_back({1});
    for (int i = 1; i < n; i++)
    {
        vector<long long int> temp(i + 1);
        temp[0] = temp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            temp[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(temp);
    }

    return res;
}
