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

    // Function to find a solved Sudoku.
    bool isSafe(int grid[9][9], int i, int j, int k)
    {
        for (int a = 0; a < 9; a++)
        {
            if (grid[i][a] == k)
                return 0;
            if (grid[a][j] == k)
                return 0;
            if (grid[(i / 3) * 3 + a / 3][(j / 3) * 3 + a % 3] == k)
                return 0;
        }
        return 1;
    }
    bool SolveSudoku(int grid[9][9])
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == 0)
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (isSafe(grid, i, j, k))
                        {
                            grid[i][j] = k;
                            if (SolveSudoku(grid))
                                return 1;
                            else
                                grid[i][j] = 0;
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }

    // Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where
    // each word is a valid dictionary word. Each dictionary word can be used more than once.
    void wordBreaker(int n, string s, unordered_set<string> st, string t, vector<string> &ans)
    {
        if (s.size() == 0)
        {
            t.pop_back();
            ans.push_back(t);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            string sb = s.substr(0, i + 1);
            if (st.find(sb) != st.end())
            {
                wordBreaker(n, s.substr(i + 1), st, t + sb + " ", ans);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        unordered_set<string> st(dict.begin(), dict.end());
        vector<string> ans;
        wordBreaker(n, s, st, "", ans);
        return ans;
    }

    // Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
    // Return a list of unique strings that are valid with the minimum number of removals.
    set<pair<int, string>> ipr;
    int getMin(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.size() > 0 and st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.size();
    }
    void invalidParenthesesRemover(string s, unordered_set<string> &ans, int ind, int count, int mra)
    {
        if (mra < 0)
            return;
        pair<int, string> x = make_pair(ind, s);
        if (ipr.find(x) != ipr.end())
            return;
        if (ind == s.size())
        {
            if (count == 0)
                ans.insert(s);
            return;
        }
        if (s[ind] == '(' or s[ind] == ')')
        {
            string temp = s;
            temp.erase(ind, 1);
            invalidParenthesesRemover(temp, ans, ind, count, mra - 1);
        }
        if (s[ind] == '(')
            count++;
        if (s[ind] == ')')
            count--;
        if (count < 0)
            return;
        ipr.insert(x);
        invalidParenthesesRemover(s, ans, ind + 1, count, mra);
    }
    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> ans;
        int mra = getMin(s);
        invalidParenthesesRemover(s, ans, 0, 0, mra);
        int mx = 0;
        for (string i : ans)
        {
            int sz = i.size();
            mx = max(mx, sz);
        }
        vector<string> ret;
        for (string i : ans)
            if (i.size() == mx)
                ret.push_back(i);
        return ret;
    }

    // Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
    bool partitionEqually(int n, int arr[], int ind, int sum)
    {
        if (ind == n)
        {
            if (sum == 0)
                return 1;
            return 0;
        }
        if (arr[ind] <= sum)
            return partitionEqually(n, arr, ind + 1, sum - arr[ind]) or partitionEqually(n, arr, ind + 1, sum);
        else
            return partitionEqually(n, arr, ind + 1, sum);
    }
    int equalPartition(int n, int arr[])
    {
        int tsum = accumulate(arr, arr + n, 0);
        if (tsum % 2)
            return 0;
        return partitionEqually(n, arr, 0, tsum / 2);
    }

    // Given a String S, Find all possible Palindromic partitions of the given String.
    bool isPalindrome(string S)
    {
        for (int i = 0; i < S.length() / 2; i++)
        {
            if (S[i] != S[S.length() - i - 1])
                return 0;
        }
        return 1;
    }
    void palindromicPerms(string s, vector<string> temp, vector<vector<string>> &ans)
    {
        if (s.size() == 0)
        {
            ans.push_back(temp);
        }
        for (int i = 0; i < s.size(); i++)
        {
            string t = s.substr(0, i + 1);
            if (isPalindrome(t))
            {
                temp.push_back(t);
                palindromicPerms(s.substr(i + 1), temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s)
    {
        vector<vector<string>> ans;
        palindromicPerms(s, {}, ans);
        return ans;
    }

    // Function to return a list of indexes denoting the required combinations whose sum is equal to given number.
    void sumCombination(vector<int> a, int sum, vector<int> temp, vector<vector<int>> &ans, int ind)
    {
        if (sum == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (sum < 0 or ind >= a.size())
            return;

        if (a[ind] <= sum)
        {
            temp.push_back(a[ind]);
            sumCombination(a, sum - a[ind], temp, ans, ind);
            temp.pop_back();
        }
        int j = ind;
        while (a[j] == a[ind])
            j++;
        sumCombination(a, sum, temp, ans, j);
    }
    vector<vector<int>> combinationSum(vector<int> &a, int b)
    {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        sumCombination(a, b, {}, ans, 0);
        return ans;
    }

    // Given a square chessboard, the initial position of Knight and position of a target.
    // Find out the minimum steps a Knight will take to reach the target position.
    int minStepToReachTarget(vector<int> KnightPos, vector<int> TargetPos, int n)
    {
        vector<pair<int, int>> dir = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
        queue<pair<pair<int, int>, int>> q;
        q.push({{KnightPos[0], KnightPos[1]}, 0});
        vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, 0));
        vis[KnightPos[0]][KnightPos[1]] = 1;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int x = top.first.first, y = top.first.second, curr = top.second;
            if (x == TargetPos[0] && y == TargetPos[1])
                return curr;
            for (auto p : dir)
            {
                int i = x + p.first, j = y + p.second;
                if (i > 0 and i <= n and j > 0 and j <= n and !vis[i][j])
                {
                    vis[i][j] = 1;
                    q.push({{i, j}, curr + 1});
                }
            }
        }
        return -1;
    }

    // Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), calculate length of the shortest safe route possible
    // from any cell in the first column to any cell in the last column of the matrix. We have to avoid landmines and their four adjacent cells (left, right, above and below)
    // as they are also unsafe. We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.
    bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &vis, int i, int j, int n, int m)
    {
        if (i < 0 or i >= n or j < 0 or j >= m or vis[i][j] or !mat[i][j])
            return 0;
        if (i - 1 >= 0 and !mat[i - 1][j])
            return 0;
        if (j - 1 >= 0 and !mat[i][j - 1])
            return 0;
        if (i + 1 < n and !mat[i + 1][j])
            return 0;
        if (j + 1 < m and !mat[i][j + 1])
            return 0;
        return 1;
    }
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<pair<int, int>> moves = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for (int i = 0; i < n; i++)
        {
            if (isSafe(mat, vis, i, 0, n, m))
            {
                q.push({{i, 0}, 1});
                vis[i][0] = 1;
            }
        }

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int x = top.first.first, y = top.first.second, cur = top.second; // cout<<x<<" "<<y<<" "<<cur<<endl;
            if (y == m - 1)
                return cur;
            for (auto p : moves)
            {
                int i = x + p.first, j = y + p.second;
                if (isSafe(mat, vis, i, j, n, m))
                { // cout<<i<<" "<<j<<endl;
                    vis[i][j] = 1;
                    q.push({{i, j}, cur + 1});
                }
            }
        }
        return -1;
    }

    // Function to find the largest number after k swaps.
    string maxNum = "";
    void maximumNumFinder(string &str, int k, int ind)
    {
        if (k == 0 or ind >= str.size())
        {
            maxNum = max(str, maxNum);
            return;
        }
        for (int i = ind + 1; i < str.size(); i++)
        {
            if (str[i] > str[ind])
            {
                swap(str[ind], str[i]);
                maximumNumFinder(str, k - 1, ind + 1);
                swap(str[ind], str[i]);
            }
        }
        maximumNumFinder(str, k, ind + 1);
    }
    string findMaximumNum(string str, int k)
    {
        maximumNumFinder(str, k, 0);
        return maxNum;
    }

    // Function to print all unique permutations of the given string in lexicographically sorted order.
    void permutationFinder(string s, string cur, set<string> &ans, vector<bool> &vis)
    {
        if (cur.size() > s.size())
            return;
        if (cur.size() == s.size())
        {
            ans.insert(cur);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (!vis[i])
            {
                cur.push_back(s[i]);
                vis[i] = 1;
                permutationFinder(s, cur, ans, vis);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<string> find_permutation(string s)
    {
        set<string> temp;
        vector<string> ans;
        vector<bool> vis(s.size() + 1, 0);
        permutationFinder(s, "", temp, vis);
        for (string s : temp)
            ans.push_back(s);
        return ans;
    }

    // Given an N x M matrix, with a few hurdles(denoted by 0) arbitrarily placed, calculate the length of the longest possible route possible
    // from source(xs,ys) to a destination(xd,yd) within the matrix. The route cannot contain any diagonal moves and a location once visited in a particular path cannot be visited again.
    void longestPathDetector(vector<vector<int>> &mat, int xs, int ys, int xd, int yd, int &ans, int curr, int n, int m)
    {
        if (mat[xs][ys] == 0)
            return;
        if (xs == xd and ys == yd)
        {
            ans = max(ans, curr);
            return;
        }
        if (xs - 1 >= 0)
        {
            mat[xs][ys] = 0;
            longestPathDetector(mat, xs - 1, ys, xd, yd, ans, curr + 1, n, m);
            mat[xs][ys] = 1;
        }
        if (xs + 1 < n)
        {
            mat[xs][ys] = 0;
            longestPathDetector(mat, xs + 1, ys, xd, yd, ans, curr + 1, n, m);
            mat[xs][ys] = 1;
        }
        if (ys - 1 >= 0)
        {
            mat[xs][ys] = 0;
            longestPathDetector(mat, xs, ys - 1, xd, yd, ans, curr + 1, n, m);
            mat[xs][ys] = 1;
        }
        if (ys + 1 < m)
        {
            mat[xs][ys] = 0;
            longestPathDetector(mat, xs, ys + 1, xd, yd, ans, curr + 1, n, m);
            mat[xs][ys] = 1;
        }
    }
    int longestPath(vector<vector<int>> mat, int xs, int ys, int xd, int yd)
    {
        int n = mat.size(), m = mat[0].size();
        int ans = -1;
        longestPathDetector(mat, xs, ys, xd, yd, ans, 0, n, m);
        return ans;
    }
};

int main()
{
    Backtracking backtracking;
    // cout << backtracking.minStepToReachTarget({4, 5}, {1, 1}, 6);
    return 0;
}