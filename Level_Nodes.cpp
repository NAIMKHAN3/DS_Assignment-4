#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int v)
    {
        val = v;
        left = right = NULL;
    }
};

Node *inputTree()
{
    int v;
    cin >> v;

    Node *root = NULL;
    queue<Node *> q;
    if (v != -1)
    {
        root = new Node(v);
        q.push(root);
    }
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        if (l != -1)
        {
            temp->left = new Node(l);
            q.push(temp->left);
        }
        if (r != -1)
        {
            temp->right = new Node(r);
            q.push(temp->right);
        }
    }
    return root;
}
int maxHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);
    return max(l, r) + 1;
}
void levelNodes(Node *root, int x, vector<int> &v)
{
    if (root == NULL)
        return;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> pr = q.front();
        q.pop();
        Node *n = pr.first;
        int level = pr.second;
        if (level == x)
            v.push_back(n->val);
        if (n->left)
            q.push({n->left, level + 1});
        if (n->right)
            q.push({n->right, level + 1});
    }
}

int main()
{
    vector<int> v;
    Node *root = inputTree();
    int l;
    cin >> l;
    int height = maxHeight(root) - 1;
   
    if (l > height)
        cout << "Invalid";
    else
    {
        levelNodes(root, l, v);
        for (int val : v)
        {
            cout << val << " ";
        }
    }

    return 0;
}