#include <bits/stdc++.h>

bool checkPalindrome(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void rec(int i, string s, vector<string> temp, vector<vector<string>> &res)
{
    if (i == s.size())
    {
        res.push_back(temp);
        return;
    }

    for (int index = i; index < s.length(); index++)
    {
        if (checkPalindrome(i, index, s))
        {
            temp.push_back(s.substr(i, index - i + 1));
            rec(index + 1, s, temp, res);
            temp.pop_back();
        }
    }
}