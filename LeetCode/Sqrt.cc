class Solution {
public:
    int sqrt(int x) {
        if(x <= 1) return x;
        long long lb = 0, ub = x;
        while(ub - lb > 1) {
            long long mid = lb + (ub - lb) / 2;
            if(mid * mid < x)
                lb = mid;
            else if(mid * mid > x)
                ub = mid;
            else
                return mid;
        }
        return lb;
    }
};