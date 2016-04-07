public class Solution {
    public void sortColors(int[] A) {
        int red = 0, white = 0;
        for(int i = 0; i < A.length; i++) {
            if(A[i] == 0) {
                A[i] = A[white];
                A[white++] = A[red];
                A[red++] = 0;
            } else if(A[i] == 1) {
                swap(A[white++], A[i]);
            } 
        }
    }
}