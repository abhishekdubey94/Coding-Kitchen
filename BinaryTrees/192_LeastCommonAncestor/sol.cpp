#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left,*right;
};

TreeNode* leastCommonAncestor(TreeNode *root,TreeNode *p,TreeNode *q){
    if(root==nullptr || root==p || root==q){
        return root;
    }
    TreeNode* left = leastCommonAncestor(root->left,p,q);
    TreeNode* right = leastCommonAncestor(root->right,p,q);

    if(left!=nullptr && right!=nullptr){
        return root;
    }
    if(left==nullptr){
        return right;
    }else{
        return left;
    }
}