import java.util.Arrays;

public class MinIntHeap {
    private int capacity = 10;
    private int size = 0;

    int[] items = new int[capacity];

    // child and parent index
    private int getLeftChildIndex(int parentIndex) {
        return parentIndex * 2 + 1;
    }

    private int getRightChildIndex(int parentIndex) {
        return parentIndex * 2 + 2;
    }

    private int getParentIndex(int childIndex) {
        return (childIndex - 1) / 2;
    }

    // has child or has parent
    private boolean hasLeftChild(int parentIndex) {
        return getLeftChildIndex(parentIndex) < size;
    }

    private boolean hasRightChild(int index) {
        return getRightChildIndex(index) < size;
    }

    private boolean hasParent(int index) {
        return getParentIndex(index) >= 0;
    }

    // get child and parent
    private int getLeftChild(int index) {
        return items[getLeftChildIndex(index)];
    }

    private int getRightChild(int index) {
        return items[getRightChildIndex(index)];
    }

    private int getParent(int index) {
        return items[getParentIndex(index)];
    }

    private void swap(int i, int j) {
        int temp = items[i];
        items[i] = items[j];
        items[j] = temp;
    }

    private void ensureCapacity() {
        if (size == capacity) {
            items = Arrays.copyOf(items, capacity * 2);
        }
        capacity *= 2;
    }

    public int peek() {
        if (size == 0)
            throw new IllegalStateException();

        return items[0];
    }

    public int poll() {
        if (size == 0) {
            throw new IllegalStateException();
        }
        int item = items[0];
        items[0] = items[size - 1];
        size--;
        heapifyDown();
        return item;
    }

    public void add(int num) {
        ensureCapacity();
        items[size] = num;
        size++;
        heapifyUp();
    }

    public void heapifyUp() {
        int index = size - 1;
        while (hasParent(index) && getParent(index) > items[index]) {
            swap(index, getParentIndex(index));
            index = getParentIndex(index);
        }
    }

    public void heapifyDown() {

        int index = 0;
        while (hasLeftChild(index)) {
            int smallerChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && getLeftChild(index) > getRightChild(index)) {
                smallerChildIndex = getRightChild(index);
            }

            if (items[index] < items[smallerChildIndex]) {
                break;
            } else {
                swap(index, smallerChildIndex);
            }
            index = smallerChildIndex;
        }

    }
}
