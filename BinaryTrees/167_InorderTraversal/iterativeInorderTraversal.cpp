#include <iostream>
#include <stack>
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

// Iterative function to perform in-order traversal of the tree
void inorderIterative(Node *root)
{
    stack<Node*> st;
    Node* curr = root;

    while(!st.empty() || curr != nullptr){
        
        if(curr!=nullptr){
            st.push(curr);
            curr = curr->left;
        }else{
            curr = st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}

int main()
{
	/* Construct below tree
              1
            /   \
           /     \
          2       3
         /      /  \
        /      /    \
       4      5      6
             / \
            /   \
           7     8
	*/

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	inorderIterative(root);

	return 0;
}

//https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/