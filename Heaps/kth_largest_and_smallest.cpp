// Normal Sort Function
#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    return {arr[k - 1], arr[n - k]};
}

// Using Heap
#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for (auto i : arr)
    {
        pq1.push(i);
        pq2.push(i);

        if (pq1.size() > k)
            pq1.pop();
        if (pq2.size() > k)
            pq2.pop();
    }

    return {pq1.top(), pq2.top()};
}
