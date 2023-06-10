// Four Sum Problem
// The following approach takes O(N^2 * N) complexity

#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int left = j + 1;
            int right = n - 1;
            int rem = target - arr[i] - arr[j];
            while (left < right)
            {
                int sum = arr[left] + arr[right];
                if (sum == rem)
                {
                    return "Yes";
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
        }
    }

    return "No";
}
