// Find the longest substring without repeating characters
// Standard question of sliding window, phew!

#include <bits/stdc++.h>
int uniqueSubstrings(string s)
{
    // Write your code here
    unordered_map<char, int> count;
    int i = 0, j = 0, res = 0;
    while (j < s.length())
    {
        count[s[j]]++;
        if (count.size() == j - i + 1)
        {
            res = max(res, j - i + 1);
        }
        else
        {
            while (count.size() < j - i + 1)
            {
                count[s[i]]--;
                if (count[s[i]] == 0)
                    count.erase(s[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        j++;
    }

    return res;
}