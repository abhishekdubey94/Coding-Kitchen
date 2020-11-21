#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *removeDuplicates(Node *root)
{
    Node *slow = root;
    Node *fast = root->next;
    
    while(fast!= nullptr && slow!=nullptr){
        while(fast!=nullptr && fast->data == slow->data)
            fast = fast->next;
        slow->next = fast;
        slow = slow->next;
        if(fast!=nullptr) fast = fast->next;
    }
    return root;
}