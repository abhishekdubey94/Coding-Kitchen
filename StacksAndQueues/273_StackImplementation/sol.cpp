#include<bits/stdc++.h>
using namespace std;

class Stack{
    static const int MAX = 1000;
    int maxCapacity ;
    int arr[MAX];
    int top ;

    public:
        Stack(int capacity){
            maxCapacity = capacity;
            top = -1;
        }

        bool isFull(){
            if(top>=maxCapacity-1){
                return true;
            }
            else 
                return false;
        }

        bool isEmpty(){
            if(top==-1){
                return true;
            }
            return false;
        }

        void push(int n){
            if(isFull()){
                cout<<"The stack is full\n";
                return;
            }
            arr[++top] = n;
        }

        int pop(){
            if(isEmpty()){
                cout<<"The stack is empty\n";
                return -1;
            }
            return arr[top--];
        }

        int peek(){
            if(isEmpty()){
                cout<<"The stack is empty()\n";
                return -1;
            }
            return arr[top];
        }
};
int main(){
    Stack st = Stack(5);
    cout<<"Empty: "<<st.isEmpty()<<endl;
    cout<<"Full: "<<st.isFull()<<endl;
    cout<<"Pop: "<<st.pop()<<endl;
    cout<<"Peek: "<<st.peek()<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout<<"Pop: "<<st.pop()<<endl;
    cout<<"Pop: "<<st.pop()<<endl;
    cout<<"Peek: "<<st.peek()<<endl;
    cout<<"Pop: "<<st.pop()<<endl;

}