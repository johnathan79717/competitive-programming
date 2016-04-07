class Bar {
    int index, height;
    Bar(int i, int h) {
        index = i;
        height = h;
    }
}

public class Solution {
    public int largestRectangleArea(int[] height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        Stack<Bar> stack = new Stack<Bar>();
        int ans = 0;
        for(int i = 0; i < height.length; i++) {
            int index = i;
            while(!stack.empty() && stack.peek().height > height[i]) {
                index = stack.peek().index;
                ans = Math.max(ans, (i - index) * stack.peek().height);
                stack.pop();
            }
            if(stack.empty() || stack.peek().height < height[i])
                stack.push(new Bar(index, height[i]));
        }
        while(!stack.empty()) {
            ans = Math.max(ans, (height.length - stack.peek().index) * stack.peek().height);
            stack.pop();
        }
        return ans;
    }
}