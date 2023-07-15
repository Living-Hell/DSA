#include <bits/stdc++.h>
using namespace std;

class Backtracking
{
private:
public:
    // Find all possible paths that the rat can take to reach from source (0,0) to destination (N-1,N-1).
    void pathFinder(vector<vector<int>> &m, int n, vector<string> &ans, string s, int i, int j, vector<vector<bool>> &vis)
    {
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || !m[i][j])
            return;
        if (i == n - 1 and j == n - 1)
        {
            ans.push_back(s);
            return;
        }
        vis[i][j] = 1;
        pathFinder(m, n, ans, s + "U", i - 1, j, vis);
        pathFinder(m, n, ans, s + "L", i, j - 1, vis);
        pathFinder(m, n, ans, s + "D", i + 1, j, vis);
        pathFinder(m, n, ans, s + "R", i, j + 1, vis);
        vis[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        pathFinder(m, n, ans, "", 0, 0, vis);
        return ans;
    }
};

int main()
{
    Backtracking backtracking;

    return 0;
}