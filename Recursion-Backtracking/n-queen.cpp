bool validPos(int row, int col, int n, vector<vector<int>> res)
{
    // check same column
    for (int i = 0; i < row; i++)
    {
        if (res[i][col] == 1)
            return false;
    }

    // check upper right diagonal
    int i = row - 1, j = col + 1;
    while (i >= 0 && j < n)
    {
        if (res[i][j] == 1)
            return false;
        i--;
        j++;
    }

    // check upper left diagonal
    i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (res[i][j] == 1)
            return false;
        i--;
        j--;
    }

    return true;
}

void rec(int i, int n, vector<vector<int>> &temp, vector<vector<int>> &res)
{
    if (i == temp.size())
    {
        vector<int> tempp;
        for (auto i : temp)
        {
            for (auto j : i)
            {
                tempp.push_back(j);
            }
        }
        res.push_back(tempp);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (validPos(i, col, n, temp))
        {
            temp[i][col] = 1;
            rec(i + 1, n, temp, res);
            temp[i][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int>> res;
    vector<vector<int>> temp(n, vector<int>(n, 0));
    rec(0, n, temp, res);
    return res;
}