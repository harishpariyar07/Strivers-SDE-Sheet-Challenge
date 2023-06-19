// The brute force approach is to just find the next permutation sequence till kth
#include <bits/stdc++.h>

string kthPermutation(int n, int k)
{
    // Write your code here.
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    k--;

    while (k > 0)
    {
        int index = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                index = i;
                break;
            }
        }

        for (int j = n - 1; j > index && index != -1; j--)
        {
            if (arr[j] > arr[index])
            {
                swap(arr[j], arr[index]);
                break;
            }
        }

        reverse(arr.begin() + index + 1, arr.end());
        k--;
    }

    string res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(arr[i] + '0');
    }

    return res;
}

// The optimal approach is bit mathy
// which takes no of permutations possible for the given subset of numbers
#include <bits/stdc++.h>

int findFact(int x)
{
    int fact = 1;
    while (x >= 1)
    {
        fact *= x;
        x--;
    }
    return fact;
}

string kthPermutation(int n, int k)
{
    // Write your code here.
    string res;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    int temp = n - 1;
    int fact = findFact(temp);
    int index = (k - 1) / fact;
    k = (k - 1) % fact;

    while (k > 0 || temp > 0)
    {
        res.push_back(arr[index] + '0');
        arr.erase(arr.begin() + index);
        temp--;
        fact = findFact(temp);
        index = k / fact;
        k = k % fact;
    }

    res.push_back(arr[0] + '0');

    return res;
}
