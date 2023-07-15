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

    // Given an integer n, find all distinct solutions to the n-queens puzzle.
    void nQueenHelper(int n, vector<vector<int>> &ans, vector<int> &temp, int col, vector<bool> ld, vector<bool> rd, vector<bool> r)
    {
        if (col >= n)
        {
            ans.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (r[row] == 0 and rd[row + col] == 0 and ld[n - 1 + col - row] == 0)
            {
                temp.push_back(row + 1);
                rd[row + col] = 1;
                ld[n - 1 + col - row] = 1;
                r[row] = 1;
                nQueenHelper(n, ans, temp, col + 1, ld, rd, r);
                temp.pop_back();
                rd[row + col] = 0;
                ld[n - 1 + col - row] = 0;
                r[row] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> ans;
        vector<bool> r(n, 0), ld(2 * n, 0), rd(2 * n, 0);
        vector<int> temp;
        nQueenHelper(n, ans, temp, 0, ld, rd, r);
        return ans;
    }
};

int main()
{
    Backtracking backtracking;

    return 0;
}