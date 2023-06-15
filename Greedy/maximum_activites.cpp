// same as that of maximum meetings

struct Meetings
{
    int st;
    int en;
};

public:
// Function to find the maximum number of meetings that can
// be performed in a meeting room.
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    Meetings m[n];
    for (int i = 0; i < n; i++)
    {
        m[i].st = start[i];
        m[i].en = end[i];
    }

    sort(m, m + n, [&](Meetings m1, Meetings m2)
         { return (m1.en < m2.en); });

    int count = 1; // the first activity has to be done at least
    int prev = 0;

    for (int i = 1; i < n; i++)
    {
        if (m[prev].en < m[i].st)
        {
            prev = i;
            count++;
        }
    }

    return count;
}