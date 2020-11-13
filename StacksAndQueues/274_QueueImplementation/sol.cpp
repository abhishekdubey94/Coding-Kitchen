#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int size, capacity, front, rear;
    int *arr;

    Queue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->front = 0;
        this->rear = capacity - 1;
        this->arr = new int[(this->capacity * sizeof(int))];
    }

    void enqueue(int val)
    {
       if(isFull()){
           return;
       }
       this->rear = (this->rear +1) % this->capacity;
        arr[rear] = val;
        this->size = this->size +1;
        cout<<"Enqueued :"<<val<<endl;
    }

    int dequeue()
    {
        if(size==0){
            return INT_MIN;
        }
        int val = arr[front];
        front = (front+1) % (capacity);
        size--;
        return val;
    }

    int getFront()
    {
        if(size==0){
            return INT_MIN;
        }
        return arr[front];
    }

    int getRear()
    {
        if(size==0){
            return INT_MIN;
        }
        return arr[rear];
    }

    bool isFull()
    {
        return this->size==this->capacity;
    }
};

int main()
{
    Queue q = Queue(3);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    cout<<q.dequeue()<<endl;
    q.getFront();
    cout<<q.dequeue()<<endl;
    q.getRear();
    return 0;
}