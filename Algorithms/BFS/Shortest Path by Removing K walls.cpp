#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k)
    {
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<vector<int>> q;
        vector<pair<int, int>> v = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        if (mat[0][0])
            k--;
        q.push({0, 0, 0, k});
        vis[0][0] = k;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int x = top[0], y = top[1], moves = top[2], k1 = top[3];

            if (x == n - 1 and y == m - 1)
                return moves;

            for (auto p : v)
            {
                int i = x + p.first, j = y + p.second;
                if (i >= 0 and i < n and j >= 0 and j < m and vis[i][j] < k1)
                {
                    if (!mat[i][j])
                    {
                        q.push({i, j, moves + 1, k1});
                        vis[i][j] = k1;
                    }
                    else if (mat[i][j] and k1 > 0)
                    {
                        q.push({i, j, moves + 1, k1 - 1});
                        vis[i][j] = k1 - 1;
                    }
                }
            }
        }
        return -1;
    }
};