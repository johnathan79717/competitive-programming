class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == (1<<31)) {
            return pow(x, n+1) / x;
        }
        if(n < 0) {
            return 1 / pow(x, -n);
        }
        double power = x, ans = 1;
        int bit = 1;
        while(bit) {
            if(n & bit) {
                ans *= power;
            }
            bit <<= 1;
            power *= power;
        }
        return ans;
    }
};