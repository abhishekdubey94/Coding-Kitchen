#include <bits/stdc++.h>
#define MAX 100
using namespace std;

class MaxHeap
{
    int size;
    int heap[MAX];

    public:
        MaxHeap()
    {
        this->size = 0;
    }
    int getParentIndex(int index) { return (index - 1) / 2; }
    int getParent(int index) { return heap[getParentIndex(index)]; }

    int getLeftChild(int index) { return heap[getLeftChildIndex(index)]; }

    int getRightChild(int index) { return heap[getRightChildIndex(index)]; }

    int getLeftChildIndex(int index) { return index * 2 + 1; }

    int getRightChildIndex(int index) { return index * 2 + 2; }

    bool hasLeftChild(int index) { return index * 2 + 1 < size; }

    bool hasRightChild(int index) { return index * 2 + 2 < size; }

    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    void peek()
    {
        if (size != 0)
        {
            cout << heap[0] << endl;
        }
        else
        {
            cout << "Empty heap";
        }
    }

    void add(int n)
    {
        if (size < MAX)
        {
            heap[size++] = n;
            heapifyUp();
        }
        else
        {
            cout << "Maximum size reached";
        }
    }

    void pop()
    {
        if (size != 0)
        {
            cout << heap[0] << endl;
            heap[0] = heap[--size];
            heapifyDown();
        }
        else
        {
            cout << "Heap is empty";
        }
    }

    void heapifyUp()
    {
        int index = size - 1;
        while (heap[index] > getParent(index))
        {
            swap(index, getParentIndex(index));
            index = getParentIndex(index);
        }
    }
    void heapifyDown()
    {
        int index = 0;
        while(hasLeftChild(index)){
            int largerChildIndex = getLeftChildIndex(index);
            if(hasRightChild(index) && getRightChild(index)>getLeftChild(index)){
                largerChildIndex = getRightChildIndex(index);
            }
            if(heap[index] > heap[largerChildIndex]){
                break;
            }else{
                swap(index,largerChildIndex);
            }
            index = largerChildIndex;
        }
    }

    
};
int main()
{
    MaxHeap mh = MaxHeap();
    mh.add(5);
    mh.add(9);
    mh.add(15);
    mh.add(2);
    mh.add(22);
    mh.add(10);
    mh.add(24);

    mh.peek();
    mh.pop();
    mh.peek();

    mh.add(19);
    mh.peek();

    return 0;
}