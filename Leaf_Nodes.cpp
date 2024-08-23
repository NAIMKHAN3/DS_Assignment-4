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
void leafNodePrintReverse(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
       cout << root->val << " ";
    if (root->right)
        leafNodePrintReverse(root->right);
    if (root->left)
        leafNodePrintReverse(root->left);
}


int main()
{

    Node *root = inputTree();
    leafNodePrintReverse(root);
    return 0;
}