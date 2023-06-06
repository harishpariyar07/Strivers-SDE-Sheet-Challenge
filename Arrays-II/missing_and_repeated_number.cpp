// Missing and Repeated Number
// This was a tricky question
// Since, we couldn't take any extra space
// I had to manipulate the array itself to find the required numbers
#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    pair<int, int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0)
            res.second = abs(index + 1);
        else
            arr[index] *= -1;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            res.first = i + 1;
            break;
        }
    }

    return res;
}