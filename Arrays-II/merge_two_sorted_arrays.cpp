// Merge two sorted arrays
// This method takes O(m+n) space since we are creating a new array for storing the elements
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.
    int i = 0, j = 0, k = 0;
    vector<int> res(arr1.size());
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            res[k] = arr1[i];
            i++;
        }
        else
        {
            res[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < m)
    {
        res[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n)
    {
        res[k] = arr2[j];
        j++;
        k++;
    }

    return res;
}

// But we have to achieve it in O(1) constant space
// First Method
// Gave the best runtime
#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int left = m - 1, right = 0;

    while (left >= 0 && right < n)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1.begin(), arr1.begin() + m);
    sort(arr2.begin(), arr2.end());

    for (int i = m; i < m + n; i++)
    {
        arr1[i] = arr2[i - m];
    }

    return arr1;
}

// Second Method (GAP Method)

#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.

    int gap = (m + n) / 2 + (m + n) % 2;
    while (gap > 0)
    {
        int i = 0, j = gap;
        while (j < m + n)
        {
            // both in arr1
            if (j < m)
            {
                if (arr1[i] > arr1[j])
                    swap(arr1[i], arr1[j]);
            }
            // both in arr2
            else if (i >= m)
            {
                if (arr2[i - m] > arr2[j - m])
                    swap(arr2[i - m], arr2[j - m]);
            }
            // i in arr1 & j in arr2
            else
            {
                if (arr1[i] > arr2[j - m])
                    swap(arr1[i], arr2[j - m]);
            }
            i++;
            j++;
        }

        if (gap == 1)
            break;

        gap = (gap / 2) + (gap % 2);
    }

    for (int i = m; i < m + n; i++)
    {
        arr1[i] = arr2[i - m];
    }

    return arr1;
}