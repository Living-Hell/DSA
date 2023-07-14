#include <bits/stdc++.h>
using namespace std;

class Greedy
{
private:
    /* data */
    long long int mod = 1e9 + 7;

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

    // Function to find out the maximum number of stocks a customer can buy with k money(initially).
    //  There is a rule that a customer can buy at most i stock on the ith day.
    int buyMaximumProducts(int n, int k, int price[])
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back({price[i], i + 1});
        }
        sort(vp.begin(), vp.end(),
             [](pair<int, int> a, pair<int, int> b)
             {
                 if (a.first == b.first)
                     return a.second < b.second;
                 return a.first < b.first;
             });
        int ans = 0;
        int i = 0;
        while (i < n and k > 0)
        {
            int stocks = vp[i].second, price = vp[i].first;
            if (stocks * price <= k)
            {
                ans += stocks;
                k -= stocks * price;
            }
            else
            {
                ans += k / price;
                k = 0;
            }
            i++;
        }
        return ans;
    }

    // Function to break this board into M * N squares such that cost of breaking is minimum.
    // The cutting cost for each edge will be given for the board in two arrays X[] and Y[].
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n)
    {
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());
        int countx = 1, county = 1, ans = 0, i = 0, j = 0;
        while (i < m - 1 and j < n - 1)
        {
            if (x[i] >= y[j])
            {
                ans += county * x[i];
                countx++;
                i++;
            }
            else
            {
                ans += countx * y[j];
                county++;
                j++;
            }
        }
        if (j < n - 1 and i == m - 1)
        {
            while (j < n - 1)
            {
                ans += countx * y[j];
                county++;
                j++;
            }
        }
        else if (i < m - 1 and j == n - 1)
        {
            while (i < m - 1)
            {
                ans += county * x[i];
                countx++;
                i++;
            }
        }
        return ans;
    }

    // Find the minimum number of days on which you need to buy food from the shop so that she can survive
    // the next S days, or determine that it isn’t possible to survive.
    int minimumDays(int s, int n, int m)
    {
        if (m > n)
            return -1;
        int tot = s * m, days = tot / n, rem = tot % n;
        if (s > 6 and 6 * n < 7 * m)
        {
            return -1;
        }
        return rem == 0 ? days : days + 1;
    }

    // The task is to find the maximum number of meetings that can be accommodated in the meeting room.
    // You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting.
    // If two meetings can be chosen for the same slot then choose meeting with smaller index in the given array.
    vector<int> maxMeetings(int n, vector<int> &s, vector<int> &f)
    {
        vector<pair<pair<int, int>, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({{s[i], f[i]}, i + 1});
        }
        sort(v.begin(), v.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
             {
                if(a.first.second == b.first.second) 
                    return a.second < b.second;
                return a.first.second < b.first.second; });

        vector<int> ans;
        int finTime = -1;

        for (auto i : v)
        {
            if (i.first.first > finTime)
            {
                ans.push_back(i.second);
                finTime = i.first.second;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    // Given an array A[]. The task is to find the maximum product possible with the subset of elements
    // present in the array. The maximum product can be a single element also.
    long long int findMaxProduct(vector<int> &a, int n)
    {
        if (n == 1)
            return a[0];
        long long int ans = 1, temp = 1, countneg = 0, countz = 0, maxneg = -11;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                if (a[i] < 0)
                {
                    maxneg = max(maxneg, (long long int)a[i]);
                    countneg++;
                }
                temp = (temp * a[i]) % mod;
            }
            else
                countz++;
        }
        if (countz == n or (countneg == 1 and countz == n - 1))
            return 0;
        if (countneg % 2 == 1)
            temp /= maxneg;
        ans = max(ans % mod, temp % mod);
        return ans;
    }

    // Function to replace any array element either arr[i] by -arr[i] or -arr[i] by arr[i] exactly
    // K number of times in such a way that after K operations, the sum of the array must be maximum.
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a + n);
        for (int i = 0; i < n and k > 0; i++)
        {
            if (a[i] < 0)
            {
                a[i] *= -1;
                k--;
            }
            else
                break;
        }

        if (k > 0 and k % 2 == 1)
        {
            sort(a, a + n);
            a[0] *= -1;
        }

        long long int ans = 0;
        ans += accumulate(a, a + n, 0);
        return ans;
    }

    // Function to write a program to find the maximum value of ∑arr[i] * i, where i = 0, 1, 2, ., n 1.
    int Maximize(int a[], int n)
    {
        long long int mod = 1e9 + 7, ans = 0;
        sort(a, a + n);
        for (long long int i = 0; i < n; i++)
            ans += a[i] * i;
        return ans % mod;
    }

    // Function to find maximum sum of the absolute difference between consecutive elements with rearrangement of array elements allowed
    long long int maxSum(int arr[], int n)
    {
        sort(arr, arr + n);
        long long int ans = 0;
        vector<int> v;
        int st = 0, end = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                v.push_back(arr[end--]);
            else
                v.push_back(arr[st++]);
        }
        v.push_back(v[0]);
        for (int i = 0; i < n; i++)
            ans += abs(v[i] - v[i + 1]);
        return ans;
    }

    // Function  to pair each element of array A to an element in array B, such that the sum of the absolute differences of all the pairs is minimum.
    long long findMinSum(vector<int> &a, vector<int> &b, int n)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(a[i] - b[i]);
        return ans;
    }

    // Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.
    long long shortestJobFirst(vector<int> &bt)
    {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        for (int i = 1; i < n; i++)
            bt[i] += bt[i - 1];
        for (int i = 1; i < n; i++)
            bt[i] += bt[i - 1];
        return bt[n - 2] / n;
    }

    // Given a sequence of pages in an array pages[] of length N and memory capacity C, find the number
    // of page faults using Least Recently Used (LRU) Algorithm.
    int pageFaults(int n, int c, int pages[])
    {
        int pfault = 0;
        deque<int> dq;
        for (int ind = 0; ind < n; ind++)
        {
            int i = pages[ind];
            if (dq.empty())
            {
                dq.push_back(i);
                pfault++;
            }
            else
            {
                auto it = find(dq.begin(), dq.end(), i);
                if (it == dq.end())
                {
                    if (dq.size() == c)
                        dq.pop_front();
                    dq.push_back(i);
                    pfault++;
                }
                else
                {
                    dq.erase(it);
                    dq.push_back(i);
                }
            }
        }
        return pfault;
    }

    // Function to choose the minimum number of elements such that their sum should be greater than the sum of the rest of the elements of the array.
    int minSubset(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        long long int ssum = 0, esum = 0;
        for (int i : arr)
            ssum += i;
        int i;
        for (i = n - 1; i >= 0; i--)
        {
            ssum -= arr[i];
            esum += arr[i];
            if (ssum < esum)
                break;
        }
        return n - i;
    }

    // Function to find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes wherever possible.
    vector<vector<int>> waterConnection(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        map<int, pair<int, int>> mp;
        for (int i = 0; i < p; i++)
            mp[a[i]] = {b[i], d[i]};
        for (auto i : mp)
        {
            int h2 = i.second.first, h1 = i.first, dia = i.second.second;
            while (mp.find(h2) != mp.end())
            {
                int h3 = mp[h2].first;
                dia = min(dia, mp[h2].second);
                mp.erase(h2);
                h2 = h3;
            }
            if (mp.find(h1) != mp.end())
            {
                mp[h1] = {h2, dia};
            }
        }
        vector<vector<int>> ans;
        for (auto i : mp)
            ans.push_back({i.first, i.second.first, i.second.second});
        return ans;
    }

    // Function to distribute chocolate packets among M students such that the difference between maximum and minimum number of chocolates given to a student is minimum.
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long ans = INT_MAX;
        for (int i = m - 1; i < n; i++)
            ans = min(ans, a[i] - a[i - m + 1]);
        return ans;
    }

    // Function to select K (K<= N) ATM servers  in such a way that the maximum distance of a city from the ATM Server is minimized.
    int selectKcities(int n, int k, vector<vector<int>> &mat)
    {
        int ans = 1e9;
        for (int i = 0; i < n; i++)
        {
            vector<int> dist(n, 1e9);
            int temp = i;
            for (int l = 0; l < k; l++)
            {
                for (int j = 0; j < n; j++)
                    dist[j] = min(dist[j], mat[temp][j]);
                temp = max_element(dist.begin(), dist.end()) - dist.begin();
            }
            ans = min(ans, dist[temp]);
        }
        return ans;
    }

    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; i++)
            pq.push(arr[i]);
        long long tcost = 0;
        while (pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long cost = a + b;
            pq.push(cost);
            tcost += cost;
        }
        return tcost;
    }

    // Function to find the smallest number with given sum of digits as S and number of digits as D.
    string smallestNumber(int sum, int d)
    {
        if (sum > d * 9)
            return "-1";
        string ans = "";
        while (d > 1 and sum > 9)
        {
            ans = "9" + ans;
            d--;
            sum -= 9;
        }
        if (d == 2 and sum == 9)
        {
            ans = "18" + ans;
            return ans;
        }
        else
        {
            if (d > 1)
            {
                ans = to_string(sum - 1) + ans;
                d--;
                sum = 1;
            }
            while (d > 1)
            {
                ans = "0" + ans;
                d--;
            }
            ans = to_string(sum) + ans;
        }
        return ans;
    }
};

int main()
{
    Greedy greedy;

    return 0;
}