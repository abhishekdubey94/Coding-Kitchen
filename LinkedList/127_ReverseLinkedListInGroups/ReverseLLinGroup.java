public class ReverseLLinGroup {
    static Node head; // head of list

    static class Node {
        int data;
        Node next;

        Node(int key) {
            data = key;
            next = null;
        }
    }

    public static Node reverse(Node node, int k) {
        int count = 0;
        Node curr = node;

        while (count < k && curr != null) {
            curr = curr.next;
            count++;
        }
        if (count == k) {
            curr = reverse(curr, k);

            while (count-- > 0) {
                Node temp = node.next;
                node.next = curr;
                curr = node;
                node = temp;
            }
            node = curr;
        }

        return node;
    }

    public static void main(String[] args) {
        /* Start with the empty list */

        push(8);
        push(7);
        push(6);
        push(5);
        push(4);
        push(2);
        push(2);
        push(1);

        System.out.println("Given linked list");
        print();

        head = reverse(head, 4);

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
