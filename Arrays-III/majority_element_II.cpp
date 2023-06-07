// Consider an element with frequency greater than the floor of (N/3) where N is the size of the array

// The Brute Force Approach with O(N^2) TC
// The Better approach with O(N) space with O(N) TC

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    unordered_map<int, int> count;
    vector<int> res;
    int n = arr.size(), cnt = n / 3;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (auto i : count)
    {
        if (i.second > cnt)
            res.push_back(i.first);
    }

    return res;
}

// The Optimal Approach with O(1) space
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int res1, res2, count1 = 0, count2 = 0;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count1 == 0 && arr[i] != res2)
        {
            res1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0 && arr[i] != res1)
        {
            res2 = arr[i];
            count2 = 1;
        }
        else if (arr[i] == res1)
        {
            count1++;
        }
        else if (arr[i] == res2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == res1)
            count1++;
        else if (arr[i] == res2)
            count2++;
    }

    if (count1 > arr.size() / 3)
        ans.push_back(res1);
    if (count2 > arr.size() / 3)
        ans.push_back(res2);

    return ans;
}