class Solution
{
public:
    void rec(int i, int sum, vector<int> temp, vector<int> arr, vector<vector<int>> &res)
    {
        if (sum == 0)
        {
            res.push_back(temp);
            return;
        }

        if (i == arr.size() || sum < 0)
        {
            return;
        }

        temp.push_back(arr[i]);
        sum -= arr[i];
        rec(i, sum, temp, arr, res);
        temp.pop_back();
        sum += arr[i];
        rec(i + 1, sum, temp, arr, res);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        vector<vector<int>> res;
        rec(0, target, temp, candidates, res);
        return res;
    }
};