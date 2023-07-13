#include <bits/stdc++.h>

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    // Write your code here.
    int n = image.size(), m = image[0].size();

    int rows[4] = {-1, 1, 0, 0};
    int cols[4] = {0, 0, 1, -1};

    queue<pair<int, int>> q;
    q.push({sr, sc});
    int c = image[sr][sc];
    image[sr][sc] = -1;

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        int i = temp.first;
        int j = temp.second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int row = i + rows[k];
            int col = j + cols[k];

            if (row >= 0 && row < n && col >= 0 && col < m && image[row][col] == c)
            {
                image[row][col] = -1;
                q.push({row, col});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (image[i][j] == -1)
                image[i][j] = color;
        }
    }

    return image;
}