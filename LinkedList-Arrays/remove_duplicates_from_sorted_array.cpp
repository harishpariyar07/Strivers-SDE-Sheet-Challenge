// using unordered_set, good for unsorted arrays

#include <bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_set<int> st;
    for (auto i : arr)
    {
        if (st.find(i) == st.end())
        {
            st.insert(i);
        }
    }
    return st.size();
}

// using a count variable and decreasing it when duplicates are encountered
#include <bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    int count = n;
    for (int i = 0; i < n; i++)
    {
        while (i + 1 < n && arr[i] == arr[i + 1])
        {
            count--;
            i++;
        }
    }
    return count;
}

// manipulating the array itself
// take i and j as pointers
// if element at ith and jth are unequal
// move i by 1 and put the jth element in that position
// and move jth pointer forward by 1

#include <bits/stdc++.h>

int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.

    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
        j++;
    }

    return i + 1;
}