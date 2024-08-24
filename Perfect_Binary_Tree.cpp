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
bool perfectBinaryTree(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL || root->left && root->right)
        return true;
    if (root->left != NULL || root->right != NULL)
        return false;

    bool r = perfectBinaryTree(root->right);

    bool l = perfectBinaryTree(root->left);
    return (r && l);
}

int main()
{
    Node *root = inputTree();
    bool ans = perfectBinaryTree(root);
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}