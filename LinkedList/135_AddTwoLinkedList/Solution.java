import java.util.Stack;

class Solution {
    class Node{
        int data;
        Node next;
        Node(int d) {
            data = d;
            next = null;
        }
    }
    static Node addLists(Node first, Node second){
        Stack<Integer> s1 = new Stack<Integer>();
        Stack<Integer> s2 = new Stack<Integer>();
        
        while(first!=null){
            s1.push(first.data);
            first = first.next;
        }
        
        while(second!=null){
            s2.push(second.data);
            second = second.next;
        }
        
        Node n = new Node(0);
        int sum = 0;
        while(!s1.isEmpty() || !s2.isEmpty()){
            if(!s1.isEmpty()) sum+=s1.pop();
            if(!s2.isEmpty()) sum+=s2.pop();
            
            n.data = sum%10;
            Node l = new Node(sum/10);
            l.next = n;
            n = l;
            sum/=10;
        }
        
        return n.data==0 ? n.next : n;
    }
}