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
};

int main()
{
    Greedy greedy;

    return 0;
}