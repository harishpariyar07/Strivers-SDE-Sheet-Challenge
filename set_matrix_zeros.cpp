#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &mat)
{
	// Write your code here.
	int row = mat.size(), col = mat[0].size();
	int zeroRow = -1;
	int zeroCol = -1;
	for (int i = 0; i < row; i++)
	{
		if (mat[i][0] == 0) 
		{
			zeroRow = i;
			break;
		}
	}

	for (int j = 0; j < col; j++)
	{
		if (mat[0][j] == 0) 
		{
			zeroCol = j;
			break;
		}
	}

	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (mat[i][j] == 0) mat[i][0] = mat[0][j] = 0;
		}
	}


	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
		}
	}

	if (zeroRow != -1)
	{
		for (int i = 0; i < row; i++)
		{
			mat[i][0] = 0;
		}
	}

	if (zeroCol != -1)
	{
		for (int j = 0; j < col; j++)
		{
			mat[0][j] = 0;
		}
	}


}