#include "bits/stdc++.h"
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter Data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    root = new Node(data);

    cout << "enter data for left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "enter data for right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void levelOrderBuildTree(Node *&root)
{
    queue<Node *> q;
    cout << "enter data for root: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "enter data for left of " << temp->data << endl;
        int leftD;
        cin >> leftD;

        if (leftD != -1)
        {
            temp->left = new Node(leftD);
            q.push(temp->left);
        }

        cout << "enter data for right of " << temp->data << endl;
        int rightD;
        cin >> rightD;

        if (rightD != -1)
        {
            temp->right = new Node(rightD);
            q.push(temp->right);
        }
    }
}
void levelOrder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
}
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    levelOrderBuildTree(root);
    levelOrder(root);

    return 0;
}
