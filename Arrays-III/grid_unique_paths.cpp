// we are at the top most left (0,0) of a given matrix.
// we need to come down to bottom most right (m-1, n-1)
// we can either move down or right at one time
// find the no of ways to reach the destination

// Recursive approach (Gives TLE)
#include <bits/stdc++.h>
int rec(int i, int j, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;

    return rec(i + 1, j, m, n) + rec(i, j + 1, m, n);
}

int uniquePaths(int m, int n)
{
    // Write your code here.
    return rec(0, 0, m, n);
}

// Memoization (Passed)
#include <bits/stdc++.h>
int rec(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = rec(i + 1, j, m, n, dp) + rec(i, j + 1, m, n, dp);
}

int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return rec(0, 0, m, n, dp);
}

// Tabulation Method (OFC Passed)
#include <bits/stdc++.h>

int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // at the first row and the first column, we can surely reach to topmost cell
            if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
            {
                int moveUp = 0, moveLeft = 0;
                if (i > 0)
                    moveUp = dp[i - 1][j];
                if (j > 0)
                    moveLeft = dp[i][j - 1];

                dp[i][j] = moveUp + moveLeft;
            }
        }
    }

    return dp[m - 1][n - 1];
}