// Standard question of greedy

#include <bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), [&](vector<int> a, vector<int> b)
         { return a[1] > b[1]; });

    int maxProfit = 0, maxTime = 0;

    for (auto i : jobs)
    {
        maxTime = max(maxTime, i[0]);
    }

    int filled[maxTime] = {0};

    for (int i = 0; i < jobs.size(); i++)
    {
        int deadline = jobs[i][0] - 1;
        while (deadline >= 0 && filled[deadline] == 1)
        {
            deadline--;
        }

        if (deadline >= 0)
        {
            filled[deadline] = 1;
            maxProfit += jobs[i][1];
        }
    }

    return maxProfit;
}
