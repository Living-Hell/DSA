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
};

int main()
{
    Greedy greedy;

    return 0;
}