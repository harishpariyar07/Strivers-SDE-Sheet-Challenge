// Using sliding window
// If the count of 0s is less than or equal to k, calculate the size of the window (j-i+1)
// If the count of 0s is greater than k, increase the ith pointer and reduce its count

int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int count[2] = {0};
    int i = 0, j = 0, res = 0;
    while (j < n)
    {
        count[arr[j]]++;

        if (count[0] <= k)
        {
            res = max(res, j - i + 1);
        }
        else if (count[0] > k)
        {
            count[arr[i]]--;
            i++;
        }
        j++;
    }

    return res;
}