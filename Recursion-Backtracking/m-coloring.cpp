#include <bits/stdc++.h>

bool check(int colors[], int c, int i, vector<vector<int>> mat)
{
    int m = mat[0].size();

    for (int j = 0; j < m; j++)
    {
        if (mat[i][j] == 1 && colors[j] == c)
            return false;
    }

    return true;
}

bool mColoring(int i, int colors[], int m, vector<vector<int>> mat)
{
    if (i == mat.size())
    {
        return true;
    }

    for (int c = 1; c <= m; c++)
    {
        if (check(colors, c, i, mat))
        {
            colors[i] = c;
            if (mColoring(i + 1, colors, m, mat))
            {
                return true;
            }
            colors[i] = 0;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    // Write your code here
    int colors[mat.size()] = {0};
    bool check = mColoring(0, colors, m, mat);
    if (check)
        return "YES";
    return "NO";
}