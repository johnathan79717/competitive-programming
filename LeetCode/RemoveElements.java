public class Solution {
    public int removeElement(int[] A, int elem) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i = 0, j = 0;
        while(j < A.length) {
            while(j < A.length && A[j] == elem)
                j++;
            if(j < A.length)
                A[i++] = A[j++];
        }
        return i;
    }
}