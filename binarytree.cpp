#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* BuildTree(vector<int>preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    
    Node* root = new Node(preorder[idx]);
    root->left = BuildTree(preorder);
    root->right = BuildTree(preorder);
    
    return root;
}

// Traversal of Tree.
// Preorder Traversal.
void preorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    cout<<root->data<<endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void InorderedTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    InorderedTraversal(root->left);
    cout<<root->data<<endl;
    InorderedTraversal(root->right);
}

void postordered(Node* root){
    if(root == nullptr){
        return;
    }

    postordered(root->left);
    postordered(root->right);
    cout<<root->data<<endl;
}

// Level ordered Traversal.
void LevelOrdered(Node* root){
    queue<Node*>q;

    q.push(root);
    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<endl;

        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

int main() { 
    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = BuildTree(preorder);
    
    
    return 0;
}
