// Put all the related values together
// Start time, End time and the Position

#include <bits/stdc++.h>

struct Meeting
{
    int start;
    int end;
    int pos;
};

bool comparator(Meeting m1, Meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    Meeting m[start.size()];

    for (int i = 0; i < start.size(); i++)
    {
        m[i].start = start[i];
        m[i].end = end[i];
        m[i].pos = i + 1;
    }

    sort(m, m + start.size(), comparator);

    vector<int> act;
    act.push_back(m[0].pos);
    int k = 0;
    for (int i = 1; i < start.size(); i++)
    {
        if (m[k].end < m[i].start)
        {
            act.push_back(m[i].pos);
            k = i;
        }
    }

    return act;
}
