#include <bits/stdc++.h>
using namespace std;

class HuffmanEncoding
{
public:
    struct Node
    {
        long long freq;
        char c;
        Node *left;
        Node *right;
        Node(char ch, int f)
        {
            freq = f;
            c = ch;
            left = NULL;
            right = NULL;
        }
        Node(int f)
        {
            c = '#';
            freq = f;
            left = NULL;
            right = NULL;
        }
    };
    struct compare
    {
        bool operator()(Node *left, Node *right)
        {
            return (left->freq > right->freq);
        }
    };
    void preorder(Node *root, vector<string> &ans, string s)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            ans.push_back(root->c + s);
            return;
        }
        if (root->left)
            preorder(root->left, ans, s + "0");
        if (root->right)
            preorder(root->right, ans, s + "1");
    }
    vector<string> huffmanCodes(string s, vector<int> f, int n)
    {
        priority_queue<Node *, vector<Node *>, compare> pq;
        for (int i = 0; i < n; i++)
        {
            Node *node = new Node(s[i], f[i]);
            pq.push(node);
        }
        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();
            Node *combo = new Node(left->freq + right->freq);
            combo->left = left;
            combo->right = right;
            pq.push(combo);
        }
        Node *root = pq.top();
        pq.pop();
        vector<string> ans;
        preorder(root, ans, "");
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    HuffmanEncoding huffman;
    vector<string> hencoding;
    hencoding = huffman.huffmanCodes(s, v, n);

    for (string i : hencoding)
        cout << i[0] << " : " << i.substr(1) << endl;
    return 0;
}