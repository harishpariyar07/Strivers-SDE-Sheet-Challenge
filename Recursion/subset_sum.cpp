// Time complexity O(2^N) as there are two choices
// Either take the element or don't take it
// Two recursive calls

void rec(int i, int sum, vector<int> arr, vector<int> &res)
{
    if (i == arr.size())
    {
        res.push_back(sum);
        return;
    }

    rec(i + 1, sum + arr[i], arr, res);
    rec(i + 1, sum, arr, res);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> res;
    rec(0, 0, arr, res);
    return res;
}

// Can be done with backtracking as well
void rec(int i, int sum, vector<int> arr, vector<int> &res)
{
    if (i == arr.size())
    {
        res.push_back(sum);
        return;
    }

    rec(i + 1, sum, arr, res);
    sum += arr[i];
    rec(i + 1, sum, arr, res);
    sum -= arr[i];
}

vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> res;
    rec(0, 0, arr, res);
    return res;
}