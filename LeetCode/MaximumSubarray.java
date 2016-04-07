public class Solution {
    private class Sum {
        public int max;
        public int left;
        public int right;
        public int sum;
        public Sum(int m, int l, int r, int s) {
            max = m;
            left = l;
            right = r;
            sum = s;
        }
    }
    
    public int maxSubArray(int[] A) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(A.length == 0) return 0;
        // int prefix = 0, ans = A[0];
        // for(int i = 0; i < A.length; i++) {
        //     ans = Math.max(ans, prefix + A[i]);
        //     prefix = Math.max(0, prefix + A[i]);
        // }
        // return ans;
        return recurse(A, 0, A.length - 1).max;
    }
    
    public Sum recurse(int[] A, int begin, int end) {
        if(begin == end)
            return new Sum(A[begin], A[begin], A[begin], A[begin]);
        Sum left = recurse(A, begin, (begin+end)/2);
        Sum right = recurse(A, (begin+end)/2+1, end);
        return new Sum(
            Math.max(left.right + right.left, Math.max(left.max, right.max)),
            Math.max(left.left, left.sum + right.left),
            Math.max(right.right, right.sum + left.right),
            left.sum + right.sum);
            
    }
}