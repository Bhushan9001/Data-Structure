#include "bits/stdc++.h"
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data= d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BuildTree(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d>root->data)
      root->right = BuildTree(root->right,d);
    else{
      root->left = BuildTree(root->left,d);
    }

    return root;
}

void Input(Node* &root){
    int data;
     cout<<"Enter Data for BST: "<<endl;
    cin>>data;

    while (data != -1)
    {
        root = BuildTree(root,data);
        cin>>data;
    }
}
void LevelOrder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{

            cout<<front->data<<" ";

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
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
bool search(Node* root , int ele){

    Node* temp = root;
     while (temp)
     {
        if(temp->data == ele) return true;

        if(temp->data < ele) temp = temp->right;
        else temp = temp->left;
     }

     return false;
     
}
Node* minval(Node* root){
    if(root == NULL)return NULL;
    Node* temp = root;

    if(temp->left) temp = temp->left;
    return temp;
}
Node* deleteNode(Node* root , int d){
    if(root == NULL) return NULL;

    if(root->data == d){
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(!root->left && root->right){
          Node* temp = root->right;
          delete root;
          return temp;
        }
        if(root->left && root->right){
            int min = minval(root->right)->data;
            root->data = min;
            root->right = deleteNode(root->right,min);
            return root;
        }
          

    }
    else if(root->data > d){
        root->left = deleteNode(root->left,d);
        return root;
    }
    else{
        root->right = deleteNode(root->right,d);
        return root;
    }
}
int main(){
    Node *root = NULL;
    Input(root);
    //5 10 4 8 6 3 7 -1
    deleteNode(root,8);
    inorder(root);
return 0;
}