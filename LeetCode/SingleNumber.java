public class Solution {
    public int singleNumber(int[] A) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = 0;
        for(int a : A)
            ans ^= a;
        return ans;
    }
}