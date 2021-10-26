public class Merge2SortedLists {
    static class Node {
        int val;
        Node next;

        public Node(int val) {
            this.val = val;
        }
    }

    public static void push(Node result, int val) {
        Node newNode = new Node(val);
        newNode.next = result;
        result = newNode;
    }

    static void printlist(Node head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public static void merge2SortedList(Node head1, Node head2) {
        Node result = new Node(0);

        Node curr1 = head1;
        Node curr2 = head2;

        while (curr1 != null && curr2 != null) {
            if (curr1.val < curr2.val) {
                push(result, curr1.val);
                curr1 = curr1.next;
            } else {
                push(result, curr2.val);
                curr2 = curr2.next;
            }
        }

        while (curr1 != null) {
            push(result, curr1.val);
            curr1 = curr1.next;
        }
        while (curr2 != null) {
            push(result, curr2.val);
            curr2 = curr2.next;
        }

        printlist(result);
    }

    public static void main(String[] args) {
        Node n1 = new Node(1);
        n1.next = new Node(2);
        n1.next.next = new Node(8);

        Node n2 = new Node(3);
        n2.next = new Node(5);
        n2.next.next = new Node(7);

        merge2SortedList(n1, n2);

    }
}
