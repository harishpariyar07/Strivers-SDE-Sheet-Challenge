#include <bits/stdc++.h>

vector<vector<int>> mergeIntervals(vector<vector<int>> &nums)
{
    // Write your code here.
    vector<vector<int>> res;
    sort(begin(nums), end(nums));

    int start = nums[0][0], end = nums[0][1];
    for (int i = 1; i < nums.size(); i++)
    {
        if (end >= nums[i][0])
        {
            end = max(nums[i][1], end);
        }
        else
        {
            res.push_back({start, end});
            start = nums[i][0];
            end = nums[i][1];
        }
    }
    res.push_back({start, end});
    return res;
}
