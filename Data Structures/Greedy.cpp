#include <bits/stdc++.h>
using namespace std;

class Greedy
{
private:
    /* data */
public:
    /* Function*/
    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({end[i], start[i]});
        sort(v.begin(), v.end());
        int i = 1, ans = 1;
        int stime = v[0].first;
        while (i < n)
        {
            if (v[i].second > stime)
            {
                ans++;
                stime = v[i].first;
            }
            i++;
        }
        return ans;
    }

    // Function to find the maximum profit and the number of jobs done.
    struct Job
    {
        int id;     // Job Id
        int dead;   // Deadline of job
        int profit; // Profit if job is over before or on deadline
    };
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<int> ans(n, 0);
        int count = 0;
        sort(arr, arr + n, [](Job a, Job b)
             { return a.profit > b.profit; });
        for (int i = 0; i < n; i++)
        {
            int ded = arr[i].dead, prof = arr[i].profit;
            for (int j = ded - 1; j >= 0; j--)
            {
                if (ans[j] == 0)
                {
                    ans[j] = prof;
                    count++;
                    break;
                }
            }
        }
        return {count, accumulate(ans.begin(), ans.end(), 0)};
    }
};

int main()
{
    Greedy greedy;

    return 0;
}