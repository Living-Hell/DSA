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

    // Function to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
    struct HuffmanNode
    {
        long long freq;
        char c;
        HuffmanNode *left;
        HuffmanNode *right;
        HuffmanNode(char ch, int f)
        {
            freq = f;
            c = ch;
            left = NULL;
            right = NULL;
        }
        HuffmanNode(int f)
        {
            c = '#';
            freq = f;
            left = NULL;
            right = NULL;
        }
    };
    struct compare
    {
        bool operator()(HuffmanNode *left, HuffmanNode *right)
        {
            return (left->freq > right->freq);
        }
    };
    void preorder(HuffmanNode *root, vector<string> &ans, string s)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            ans.push_back(s);
            return;
        }
        if (root->left)
            preorder(root->left, ans, s + "0");
        if (root->right)
            preorder(root->right, ans, s + "1");
    }
    vector<string> huffmanCodes(string s, vector<int> f, int n)
    {
        priority_queue<HuffmanNode *, vector<HuffmanNode *>, compare> pq;
        for (int i = 0; i < n; i++)
        {
            HuffmanNode *node = new HuffmanNode(s[i], f[i]);
            pq.push(node);
        }
        while (pq.size() > 1)
        {
            HuffmanNode *left = pq.top();
            pq.pop();
            HuffmanNode *right = pq.top();
            pq.pop();
            HuffmanNode *combo = new HuffmanNode(left->freq + right->freq);
            combo->left = left;
            combo->right = right;
            pq.push(combo);
        }
        HuffmanNode *root = pq.top();
        pq.pop();
        vector<string> ans;
        preorder(root, ans, "");
        return ans;
    }

    // Function to form lexicographically smallest string by chosing two characters in the string and
    // replacing all the occurences of the first and second character.
    string chooseandswap(string s)
    {
        int n = s.size();
        vector<int> a(26, -1);
        for (int i = 0; i < n; i++)
        {
            if (a[s[i] - 'a'] == -1)
                a[s[i] - 'a'] = i;
        }
        char st = '#', rep;
        for (int i = 0; i < n; i++)
        {
            bool flag = 0;
            for (int j = 0; j < s[i] - 'a'; j++)
            {
                if (a[j] > i)
                {
                    rep = s[i];
                    st = 'a' + j;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (st == '#')
            return s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == rep)
                s[i] = st;
            else if (s[i] == st)
                s[i] = rep;
        }
        return s;
    }

    // Function to find the minimum number of coins and/or notes needed to make the change for Rs N.
    vector<int> minPartition(int n)
    {
        vector<int> v = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int i = 0;
        vector<int> ans;
        while (n > 0)
        {
            if (n >= v[i])
            {
                while (n >= v[i])
                {
                    n -= v[i];
                    ans.push_back(v[i]);
                }
            }
            i++;
        }
        return ans;
    }

    // Function to get the maximum total value in the knapsack.
    struct Item
    {
        int value;
        int weight;
    };
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr + n, [](Item a, Item b)
             { return (float)a.value / (float)a.weight > (float)b.value / (float)b.weight; });
        double ans = 0;
        int i = 0;
        while (i < n and w > 0)
        {
            if (w > arr[i].weight)
            {
                ans += arr[i].value;
                w -= arr[i].weight;
            }
            else
            {
                float ratio = (float)w / (float)arr[i].weight;
                ans += ratio * arr[i].value;
                w -= ratio * arr[i].weight;
            }
            i++;
        }
        return ans;
    }

    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);
        int count = 0, ans = 0;
        int i = 0, j = 0;
        while (i < n and j < n)
        {
            if (arr[i] <= dep[j])
            {
                i++;
                count++;
                ans = max(ans, count);
            }
            else
            {
                j++;
                count--;
            }
        }
        return ans;
    }

    // Function to tell the maximum number of trains for which you can provide stoppage at your station
    int maxStop(int n, int m, vector<vector<int>> &trains)
    {
        for (int i = 0; i < m; i++)
            trains[i].push_back(i);
        sort(trains.begin(), trains.end(),
             [](vector<int> a, vector<int> b)
             {
                 if (a[1] == b[1])
                     return a[3] < b[3];
                 return a[1] < b[1];
             });
        vector<int> platform(n + 1, -1);
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (platform[trains[i][2]] <= trains[i][0])
            {
                ans++;
                platform[trains[i][2]] = trains[i][1];
            }
        }
        return ans;
    }

    // Function to find what is the minimum amount of money you have to spend to buy all the N different
    // candies. You buy one candy and get K other candies for free.
    vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies, candies + n);
        int mn = 0, mx = 0;
        int to_buy = ceil((float)n / (float)(k + 1));
        for (int i = 0; i < to_buy; i++)
        {
            mn += candies[i];
            mx += candies[n - i - 1];
        }
        return {mn, mx};
    }
};

int main()
{
    Greedy greedy;

    return 0;
}