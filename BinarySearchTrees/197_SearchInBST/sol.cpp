#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
int data;
TreeNode* left;
TreeNode* right;
};
int main(){

    return 0;
}

TreeNode* search(TreeNode* root,int key){
    
    if(root==NULL || root->data==key){
        return root;
    }
    else if(root->data>key){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}