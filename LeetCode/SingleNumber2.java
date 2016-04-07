public class Solution {
    public int singleNumber(int[] A) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = 0;
        for(int mask = 1; mask != (mask << 1); mask <<= 1) {
            int cnt = 0;
            // return mask;
            for(int i = 0; i < A.length; i++) {
                if((A[i] & mask) != 0) {
                    cnt++;
                }
            }
            // return cnt;
            if(cnt % 3 != 0) {
                ans |= mask;
            }
        }
        return ans;
        // return 2;
    }
}