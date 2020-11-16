#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

bool detectLoop(Node* head)
{
    Node *fast=head,*slow=head;
    
    while(fast!=nullptr && fast->next!=nullptr && slow!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}