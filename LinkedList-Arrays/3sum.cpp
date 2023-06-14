// TC is O(logn) for sorting + O(n * n (two pointer)) for searching the elements

#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    for (int i = 0; i < n - 2; i++)
    {
        int rem = K - arr[i];
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[left] + arr[right];
            if (sum == rem)
            {
                res.push_back({arr[i], arr[left], arr[right]});

                while (left < right && res.back()[1] == arr[left])
                    left++;
                while (left < right && res.back()[2] == arr[right])
                    right--;
            }
            else if (sum < rem)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        while (i + 1 < n && arr[i] == arr[i + 1])
            i++;
    }

    return res;
}