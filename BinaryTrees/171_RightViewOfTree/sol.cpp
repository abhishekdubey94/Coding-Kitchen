#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// Should return  right view of tree
vector<int> rightView(Node *root)
{
    vector<int> ans;
    if(root==nullptr){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int s = q.size();
        for(int i=0;i<s;i++){
            Node *temp = q.front();
            if(i==s-1){
                ans.push_back(temp->data);
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            q.pop();
        }
    }
    return ans;
}