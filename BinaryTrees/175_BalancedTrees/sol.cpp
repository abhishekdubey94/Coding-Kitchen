#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
};

int height(Node *root){
    if(root==nullptr){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(Node *root)
{
    if(root==nullptr){
        return true;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh)<2 && isBalanced(root->left) && isBalanced(root->right)){
        return true;
    }
    return false;
}