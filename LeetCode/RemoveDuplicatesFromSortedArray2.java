public class Solution {
    public int removeDuplicates(int[] A) {
        if(A.length <= 2) return A.length;
        int to = 2, from = 2, prev1 = A[1], prev2 = A[0];
        while(true) {
            while(from < A.length && A[from] == prev1 && A[from] == prev2) {
                prev2 = prev1;
                prev1 = A[from++];
            }
            if(from < A.length) {
                prev2 = prev1;
                prev1 = A[from];
                A[to++] = A[from++];
            } else
                break;
        }
        return to;
    }
}