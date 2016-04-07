class Solution {
public:
    int uniquePaths(int m, int n) {
        return c(m + n - 2, n - 1);
    }
    long long c(int m, int n) {
        if(n == 0) return 1;
        if(m == 0) return 0;
        return c(m-1, n-1) * m / n;
    }
};