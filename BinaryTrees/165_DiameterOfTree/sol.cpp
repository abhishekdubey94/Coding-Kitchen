#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left,*right;

};

int height(Node* node){
    if(node==nullptr){
        return 0;
    }
    
    return max(height(node->left)+1,height(node->right)+1);
}
int diameter(Node* node) {
    if(node==nullptr){
        return 0;
    }
    
    int lheight = height(node->left);
    int rheight = height(node->right);
    
    int ldia = diameter(node->left);
    int rdia = diameter(node->right);
    
    return max(ldia,max(rdia,lheight+rheight+1));
}