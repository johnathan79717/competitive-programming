public class Solution {
    public void rotate(int[][] matrix) {
        int lb = 0, ub = matrix.length - 1;
        do {
            for(int i = 0; i < ub - lb; i++) {
                int temp = matrix[lb][lb+i];
                matrix[lb][lb+i] = matrix[ub-i][lb];
                matrix[ub-i][lb] = matrix[ub][ub-i];
                matrix[ub][ub-i] = matrix[lb+i][ub];
                matrix[lb+i][ub] = temp;
            }
        } while(++lb < --ub);        
    }
}