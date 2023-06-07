// Consider an element with frequency greater than the floor of (N/2) where N is the size of the array

// The Brute Force Approach with O(N^2) TC
// The Better approach with O(N) space with O(N) TC

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    unordered_map<int, int> count;
    int cnt = n / 2, index = -1;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (auto i : count)
    {
        if (i.second > cnt)
            return i.first;
    }
    return -1;
}

// The Optimal Approach with O(1) space
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    int res = arr[0], count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            res = arr[i];
            count = 1;
        }
        else if (arr[i] == res)
            count++;
        else
            count--;
    }

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == res)
            count1++;
    }

    if (count1 > n / 2)
        return res;
    return -1;
}