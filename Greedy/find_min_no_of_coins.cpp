// Normal greedy approach
// Take as much as no of highest value coins possible and reduce the amount at each step

#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    // Write your code here
    vector<int> coins{1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int count = 0;
    int i = coins.size() - 1;
    while (amount > 0)
    {
        while (coins[i] <= amount)
        {
            amount -= coins[i];
            count++;
        }
        i--;
    }

    return count;
}
