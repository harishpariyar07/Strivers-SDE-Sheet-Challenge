// Search in 2D matrix
// We apply binary search and there is a little math/trick to find the respective row and col

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int left = 0, right = n * m - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int row = mid / m;
        int col = mid % m;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}