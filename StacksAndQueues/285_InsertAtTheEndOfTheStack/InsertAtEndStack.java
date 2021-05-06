import java.util.*;

class InserAtEndStack {
    public static void main(String[] args) {

        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);

        System.out.println("Before");
        System.out.println("Bottom");
        printStack(st);
        System.out.println("Top");

        System.out.println("Adding number to the bottom of the stack: 7");
        addToTheBottom(st, 7);
        System.out.println("Before");
        System.out.println("Bottom");
        printStack(st);
        System.out.println("Top");
    }

    private static void addToTheBottom(Stack<Integer> st, int i) {
        if (st.isEmpty()) {
            st.push(i);
            return;
        }

        int x = st.pop();
        addToTheBottom(st, i);
        st.push(x);
    }

    public static void printStack(Stack<Integer> st) {
        if (st.isEmpty()) {
            return;
        }

        int x = st.peek();
        st.pop();

        printStack(st);

        System.out.println(x);

        st.push(x);
    }
}