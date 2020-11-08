#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
	}
};

void preOrder(Node* root){
    if(root==nullptr){
        return;
    }

    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);
}

void convertToMirror(Node* root, Node** mirror){
    if(root==NULL){
        *mirror = NULL;
        return;
    }

    *mirror = new Node(root->data);

    convertToMirror(root->left,&((*mirror)->right));
    convertToMirror(root->right,&((*mirror)->left));

}

int main()
{
    Node* root = nullptr;
    
    root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

    Node* mirror = NULL;
    convertToMirror(root, &mirror);
    preOrder(mirror);

    return 0;
}