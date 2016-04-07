public class Solution {
    public int removeDuplicates(int[] A) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(A.length == 0) return 0;
        int prev = 0, curr = 1, move = 1;
        while(curr < A.length) {
            if(A[prev] != A[curr]) {
                A[move++] = A[curr];
                prev = curr;
            }
            curr++;
        }
        return move;
    }
}