class Solution {
public:
    void f(stack<int> &s, int func(int, int)) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        s.push(func(b, a));
    }

    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for(string token : tokens) {
            if(token == "+") {
                f(s, [](int b, int a) { return b + a; });
                // int a = s.top(); s.pop();
                // int b = s.top(); s.pop();
                // s.push(b + a);
            }
            else if(token == "-") {
                f(s, [](int b, int a) { return b - a; });
                // int a = s.top(); s.pop();
                // int b = s.top(); s.pop();
                // s.push(b - a);
            }
            else if(token == "*") {
                f(s, [](int b, int a) { return b * a; });
                // int a = s.top(); s.pop();
                // int b = s.top(); s.pop();
                // s.push(b * a);
            }
            else if(token == "/") {
                f(s, [](int b, int a) { return b / a; });
                // int a = s.top(); s.pop();
                // int b = s.top(); s.pop();
                // s.push(b / a);
            } else
                s.push(atoi(token.c_str()));
        }
        return s.top();
    }
    //         Stack<Integer> stack = new Stack<Integer>();
    //     for(String s : tokens) {
    //         if(s == "+")
    //             stack.push(stack.pop() + stack.pop());
    //         else if(s == "-")
    //             stack.push(-stack.pop() + stack.pop());
    //         else if(s == "*")
    //             stack.push(stack.pop() * stack.pop());
    //         else if(s == "/") {
    //             Integer a = stack.pop(), b = stack.pop();
    //             stack.push(b / a);
    //         } else
    //             stack.push(new Integer(s));
    //     }
    //     return stack.pop();
    // }
};