int check(int mid, int n, int m)
{
    long long temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp = temp * mid;
        if (temp > m)
            return 1;
    }

    if (temp == m)
        return 0;
    return -1;
}

int findRoot(int n, int m)
{
    int left = 1, right = m;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int res = check(mid, n, m);
        if (res == 0)
        {
            return mid;
        }
        else if (res == 1)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int NthRoot(int n, int m)
{
    // Write your code here.
    if (n == 1)
        return m;
    return findRoot(n, m);
}