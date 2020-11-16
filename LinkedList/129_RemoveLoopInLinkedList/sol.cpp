#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

void removeLoop2(Node *slow,Node* head){
    Node *curr = slow;
    Node *ptr = head;
    
    while(1){
        curr = slow;
        
        while(curr->next!=slow && curr->next!=ptr){
            curr = curr->next;
        }
        
        if(curr->next == ptr){
            break;
        }
        ptr = ptr->next;
    }
    curr->next = NULL;
}

void removeLoop(Node* head)
{
    Node *fast=head,*slow=head;
    
    while(fast!=nullptr && slow!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            removeLoop2(slow,head);
        }
    }
}