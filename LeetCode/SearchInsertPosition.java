public class Solution {
    public int searchInsert(int[] A, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(A.length == 0) return 0;
        int lb = -1, ub = A.length;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(A[mid] < target)
                lb = mid;
            else
                ub = mid;
        }
        return ub;
    }
}