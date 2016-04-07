public class Solution {
    int upper_bound(int[] A, int target) {
        int lb = -1, ub = A.length;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(A[mid] > target)
                ub = mid;
            else
                lb = mid;
        }
        return ub;
    }
    
    int lower_bound(int[] A, int target) {
        int lb = -1, ub = A.length;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(A[mid] >= target)
                ub = mid;
            else
                lb = mid;
        }
        return ub;
    }
    
    public int[] searchRange(int[] A, int target) {
        int[] ans = { lower_bound(A, target), upper_bound(A, target) };
        if(ans[0] == ans[1]) {
            ans[0] = -1;
            ans[1] = -1;
        } else
            ans[1]--;
        return ans;
    }
}