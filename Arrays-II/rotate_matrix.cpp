// LeetCode Solution
// Here, we need to rotate the matrix by 90 degree

void rotate(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    // finding the transpose of a matrix first
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // reversing each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            swap(mat[i][j], mat[i][m - j - 1]);
        }
    }
}

// Coding Ninjas's Solution (TBA)
// Here, we need to rotate the matrix clockwise
// Just a variation of spiral matrix
// We need to update the matrix smartly as given in the question
#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    while (top < bottom && left < right)
    {
        int temp = mat[top][left];

        for (int i = left + 1; i <= right; i++)
        {
            swap(temp, mat[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            swap(temp, mat[i][right]);
        }
        right--;

        for (int i = right; i >= left; i--)
        {
            swap(temp, mat[bottom][i]);
        }
        bottom--;

        for (int i = bottom; i >= top; i--)
        {
            swap(temp, mat[i][left]);
        }
        left++;

        mat[top - 1][left - 1] = temp;
    }
}