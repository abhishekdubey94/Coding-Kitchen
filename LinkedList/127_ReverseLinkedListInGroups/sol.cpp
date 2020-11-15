#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

Node* reverse(Node* head,int k){
    Node* current = head;
    Node* next= NULL;
    Node* prev= NULL;
    int count =0;

    while(current!=nullptr && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next!=nullptr){
        head->next = reverse(next,k);
    }

    return prev;
}