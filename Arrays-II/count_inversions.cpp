// Count Inversion
// This question is quite tricky
// It utilizes merge sort in a smart way to calculate the count of inversions

#include <bits/stdc++.h>

int rec(int left, int mid, int right, long long *arr)
{
    vector<long long> temp;
    int i = left, j = mid + 1;
    int count = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            count += mid - i + 1;
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }

    return count;
}

int mergeSort(int left, int right, long long *arr)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        int leftPart = mergeSort(left, mid, arr);
        int rightPart = mergeSort(mid + 1, right, arr);
        int res = rec(left, mid, right, arr);
        return leftPart + rightPart + res;
    }
    return 0;
}

long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return mergeSort(0, n - 1, arr);
}