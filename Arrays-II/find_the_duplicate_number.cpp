// Question 10
// 1st approach using unordered_set
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_set<int> s;
    for (auto i : arr)
    {
        if (s.find(i) != s.end())
            return i;
        s.insert(i);
    }
    return -1;
}

// 2nd approach using Slow and Fast pointer
// Floyd’s cycle finding algorithm or Hare-Tortoise algorithm

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    int slow = arr[0], fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}
