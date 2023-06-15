// Standard greedy question 
// Just deal with double values and typecast it properly

#include <bits/stdc++.h>
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), [&](pair<int, int> a, pair<int, int> b)
         { return (a.second) / double(a.first) > (b.second) / double(b.first); });

    double profit = 0;
    for (int i = 0; i < n && w > 0; i++)
    {
        if (items[i].first <= w)
        {
            w -= items[i].first;
            profit += (items[i].second);
        }
        else
        {
            profit += (items[i].second * w) / double(items[i].first);
            w = 0;
        }
    }

    return profit;
}