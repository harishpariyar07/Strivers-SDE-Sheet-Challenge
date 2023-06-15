class Solution
{
public:
    void rec(int index, int sum, vector<int> temp, vector<int> arr, vector<vector<int>> &res)
    {
        if (sum == 0)
        {
            res.push_back(temp);
            return;
        }

        if (index == arr.size() || sum < 0)
        {
            return;
        }

        for (int i = index; i < arr.size(); i++)
        {
            if (i != index && arr[i] == arr[i - 1])
                continue;
            temp.push_back(arr[i]);
            sum -= arr[i];
            rec(i + 1, sum, temp, arr, res);
            temp.pop_back();
            sum += arr[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> temp;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        rec(0, target, temp, candidates, res);
        return res;
    }
};