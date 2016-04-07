public class Solution {
    public int trap(int[] A) {
        int[] left = new int[A.length + 1];
        left[0] = 0;
        for(int i = 0; i < A.length; i++)
            left[i+1] = Math.max(left[i], A[i]);
        int[] right = new int[A.length + 1];
        right[A.length] = 0;
        for(int i = A.length - 1; i >= 0; i--)
            right[i] = Math.max(right[i+1], A[i]);
            
        int ans = 0;
        for(int i = 0; i < A.length; i++) {
            ans += Math.max(0, Math.min(left[i], right[i+1]) - A[i]);
        }
        return ans;
    }
}