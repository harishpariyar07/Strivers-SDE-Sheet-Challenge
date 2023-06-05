#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int i = 0, j = 0, maxProfit = 0;
    while (j < prices.size())
    {
        if (prices[j] > prices[i])
        {
            maxProfit = max(maxProfit, prices[j] - prices[i]);
            j++;
        }
        else
        {
            i = j;
            j++;
        }
    }

    return maxProfit;
}