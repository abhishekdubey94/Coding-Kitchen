#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node{
    int data;
    Node *left,*right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
}

Node* buildTree(string str){
    //corner case
    if(str.length()==0 || str[0]=='N')
        return NULL;

        // creating vector of strings from input
        // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str;iss>>str;)
        ip.push_back(str);
    
    Node *root = newNode(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i<ip.size()){
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if(currVal!="N"){
            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);

        }
        i++;
        if(i>=ip.size())
            break;
        currVal = ip[i];

        if(currVal!="N"){
            currNode->right = newNode(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

vector<int> leftView(Node *root);

int main(){
    int t;
    string tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--){
        string s,ch;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> res = leftView(root);
        for(int i:res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}



vector<int> leftView(Node *root)
{
    vector<int> ans;
   if(root==nullptr){
       return ans;
   }
   
   Node *curr = root;
   ans.push_back(curr->data);
   while(curr->left || curr->right){
       if(curr->left){
           curr = curr->left;
           ans.push_back(curr->data);
       }else{
           curr = curr->right;
           ans.push_back(curr->data);
       }
   }
   
   return ans;
}