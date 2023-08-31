#include <bits/stdc++.h>
using namespace std;

class z_Algo
{
public:
    // Given two strings, one is a text string and the other is a pattern string.
    // The task is to print the indexes of all the occurrences of the pattern string in the text string
    vector<int> search(string pat, string txt)
    {
        txt = pat + "$" + txt;
        int n = txt.size();
        vector<int> z(n);
        z[0] = 0;
        int left = 0, right = 0;
        for (int i = 1; i < n; i++)
        {
            if (i > right)
            {
                left = right = i;
                while (right < n and txt[right] == txt[right - left])
                    right++;
                z[i] = right - left;
                right--;
            }
            else
            {
                int k = i - left;
                if (z[k] < right - i + 1)
                {
                    z[i] = z[k];
                }
                else
                {
                    left = i;
                    while (right < n and txt[right] == txt[right - left])
                        right++;
                    z[i] = right - left;
                    right--;
                }
            }
        }
        vector<int> ans;
        int pl = pat.size();
        for (int i = 0; i < n; i++)
            if (z[i] == pl)
                ans.push_back(i - pl);
        return ans;
    }
};