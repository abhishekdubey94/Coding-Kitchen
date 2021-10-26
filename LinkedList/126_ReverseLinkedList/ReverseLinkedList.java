public class ReverseLinkedList {
    static Node head; // head of list

    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    static Node reverse(Node head) {
        if (head == null) {
            return null;
        }
        if (head.next == null) {
            return head;
        }

        Node restReversed = reverse(head.next);
        head.next.next = head;
        head.next = null;

        return restReversed;
    }

    static Node reverseIteratively(Node head) {
        if (head == null || head.next == null) {
            return head;
        }
        Node prev = null;
        Node current = head;
        Node next = null;

        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    /* Driver program to test above function */
    public static void main(String args[]) {
        /* Start with the empty list */

        push(20);
        push(4);
        push(15);
        push(85);

        System.out.println("Given linked list");
        print();

        head = reverseIteratively(head);

        System.out.println("Reversed Linked list");
        print();
    }

    /* Function to print linked list */
    static void print() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    static void push(int data) {
        Node temp = new Node(data);
        temp.next = head;
        head = temp;
    }
}
