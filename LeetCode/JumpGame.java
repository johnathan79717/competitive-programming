public class Solution {
    public boolean canJump(int[] A) {
        int reach = 0;
        for(int i = 0; i < A.length; i++) {
            if(reach < i) return false;
            reach = Math.max(reach, i + A[i]);
        }
        return true;
    }
}