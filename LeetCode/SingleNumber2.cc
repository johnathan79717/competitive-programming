class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = 0;
        for(int mask = 1; mask; mask <<= 1) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(A[i] & mask) {
                    cnt++;
                }
            }
            if(cnt % 3 != 0) {
                ans |= mask;
            }
        }
        return ans;
    }
};