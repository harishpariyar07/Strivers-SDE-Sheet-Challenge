// The concept is similar to that of count no of inversions
// Just the difference is in the movement of pointers

#include <bits/stdc++.h>

int rec(int left, int mid, int right, vector<int> &arr)
{
    vector<int> temp;
    int i = left, j = mid + 1;
    int count = 0;
    while (i <= mid)
    {
        while (j <= right && arr[i] > 2 * (long long)arr[j])
        {
            j++;
        }
        count += j - mid - 1;
        i++;
    }

    i = left, j = mid + 1;

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

int mergeSort(int left, int right, vector<int> &arr)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        int count = mergeSort(left, mid, arr);
        count += mergeSort(mid + 1, right, arr);
        count += rec(left, mid, right, arr);
        return count;
    }
    return 0;
}

int reversePairs(vector<int> &arr, int n)
{
    // Write your code here.
    return mergeSort(0, arr.size() - 1, arr);
}