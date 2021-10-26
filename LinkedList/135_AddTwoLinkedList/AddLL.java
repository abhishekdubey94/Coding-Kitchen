public class AddLL {
    static class Node {
        int val;
        Node next;

        public Node(int val) {
            this.val = val;
        }
    }

    static Node result, cur;
    static int carry;

    public static int getSize(Node head) {
        if (head == null) {
            return 0;
        }
        Node curr = head;
        int count = 1;
        while (curr != null) {
            curr = curr.next;
            count++;
        }
        return count;
    }

    public static void addSameSizeList(Node head1, Node head2) {
        if (head1 == null || head2 == null) {
            return;
        }
        addSameSizeList(head1.next, head2.next);

        int sum = head1.val + head2.val + carry;
        carry = sum / 10;
        sum = sum % 10;
        Node newNode = new Node(sum);
        newNode.next = result;
        result = newNode;
    }

    public static void addLists(Node head1, Node head2) {
        int n1 = getSize(head1);
        int n2 = getSize(head2);
        if (n1 == n2) {
            addSameSizeList(head1, head2);
        } else {
            if (n1 < n2) {
                Node temp = head2;
                head2 = head1;
                head1 = temp;
            }

            int diff = Math.abs(n1 - n2);
            Node temp = head1;
            while (diff-- >= 0) {
                cur = temp;
                temp = temp.next;
            }

            addSameSizeList(cur, head2);

            propagateCarry(head1);

        }
        if (carry > 0) {
            Node newNode = new Node(carry);
            newNode.next = result;
            result = newNode;
        }
    }

    private static void propagateCarry(Node head1) {
        if (head1 != cur) {
            propagateCarry(head1.next);
            int sum = carry + head1.val;
            carry = sum / 10;
            sum %= 10;
            Node newNode = new Node(carry);
            newNode.next = result;
            result = newNode;
        }
    }

    // Function to print linked list
    static void printlist(Node head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public static void main(String[] args) {
        Node n1 = new Node(9);
        n1.next = new Node(2);
        n1.next.next = new Node(1);

        Node n2 = new Node(9);
        n2.next = new Node(3);
        n2.next.next = new Node(1);

        addLists(n1, n2);

        printlist(result);
    }
}
