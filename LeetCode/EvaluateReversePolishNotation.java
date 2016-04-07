public class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<Integer>();
        for(String s : tokens) {
            if(s == "+")
                stack.push(stack.pop() + stack.pop());
            else if(s == "-")
                stack.push(-stack.pop() + stack.pop());
            else if(s == "*")
                stack.push(stack.pop() * stack.pop());
            else if(s == "/") {
                Integer a = stack.pop(), b = stack.pop();
                stack.push(b / a);
            } else
                stack.push(new Integer(s));
        }
        return stack.peek();
    }
}