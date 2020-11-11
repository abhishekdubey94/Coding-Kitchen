
#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node *left,*right;
};

Node* lca(Node* root ,int n1 ,int n2 )
{
   if(root==nullptr || root->data==n1 || root->data==n2){
       return root;
   } 
   Node *left = lca(root->left,n1,n2);
   Node *right = lca(root->right,n1,n2);
   
   if(left!=nullptr && right!=nullptr){
       return root;
   }
   if(left!=nullptr){
       return left;
   }
   else{
       return right;
   }
}

int distance(Node* root, int a){
    if(root==nullptr){
        return INT_MIN;
    }
    if(root->data==a){
        return 0;
    }
    
    return max(distance(root->left,a)+1,distance(root->right,a)+1);
    
}

int findDist(Node* root, int a, int b) {
    Node* l = lca(root,a,b);
    return distance(l,a)+distance(l,b);
}