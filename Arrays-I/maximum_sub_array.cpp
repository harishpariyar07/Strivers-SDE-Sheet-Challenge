// using kadane algo
#include <bits/stdc++.h>
long long maxSubarraySum(int arr[], int n)
{
    long long currSum = 0, maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        currSum = max(currSum, (long long)0);
    }

    return maxSum;
}