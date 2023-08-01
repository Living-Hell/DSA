#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the find the smallest possible value of D such that when we add K more gas stations,
    // D, the maximum distance between adjacent gas stations, is minimized
    int helper(vector<int> &stations, double maxDist)
    {
        int tstations = 0;
        for (int i = 1; i < stations.size(); i++)
        {
            tstations += floor((stations[i] - stations[i - 1]) / maxDist);
        }
        return tstations;
    }
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        double low = 0, high = stations[stations.size() - 1] - stations[0];
        while (high - low > 1e-6)
        {
            double mid = (low + high) / 2.0;
            int station = helper(stations, mid);
            if (station > k)
                low = mid;
            else
                high = mid;
        }
        return high;
    }
};