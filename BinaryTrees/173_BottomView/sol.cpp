#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

void getBottomView(Node *root,int hd,int vd, map<int,pair<int,int>> &m){
    if(root!=nullptr){
        getBottomView(root->left,hd-1,vd+1,m);
        
        if(m.find(hd)==m.end() || vd >= m[hd].second){
            m[hd] = {root->data,vd};
        }
        
        getBottomView(root->right,hd+1,vd+1,m);
    }
}

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
   map<int,pair<int,int>> m;
   vector<int> ans;
   getBottomView(root,0,0,m);
   
   for(auto it : m){
       ans.push_back(it.second.first);
   }
   return ans;
}