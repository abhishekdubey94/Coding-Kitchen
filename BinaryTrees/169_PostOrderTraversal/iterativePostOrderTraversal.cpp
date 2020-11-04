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

// Iterative function to perform post-order traversal of the tree
void postorderIterative(Node* root)
{
    stack<Node*> st;
    st.push(root);

    stack<int> out;

    while(!st.empty()){
        Node* curr = st.top();
        st.pop();

        out.push(curr->data);

        if(curr->left!=nullptr){
            st.push(curr->left);
        }

        if(curr->right!=nullptr){
            st.push(curr->right);
        }
    }

    while(!out.empty()){
        cout<<out.top()<<" ";
        out.pop();
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

	postorderIterative(root);

	return 0;
}


//https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/