#include<bits/stdc++.h>
using namespace std;

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

void topView(Node* root,int hd,int vd, map<int,pair<int,int>> &m){
    if(root!=nullptr){
        if(m.find(hd)==m.end() || vd < m[hd].second){
            m[hd] = {root->data,vd};
        }

        topView(root->left,hd-1,vd+1,m);
        topView(root->right,hd+1,vd+1,m);
    }
    
}
int main(){
    map<int,pair<int,int>> m;

    Node* root = nullptr;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

    topView(root,0,0,m);

    for (auto it: m)
		cout << it.second.first << " ";
    return 0;
}
