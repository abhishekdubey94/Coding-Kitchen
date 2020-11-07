#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left,*right;
};

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    
    if(root==nullptr){
        return ans;
    }
    
    stack<int> st ;
    stack<int> temp;
    
    queue<Node*> q;
    
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node *t = q.front();
            q.pop();
            if(t->left)  q.push(t->left);
            if(t->right) q.push(t->right);
            temp.push(t->data);
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}