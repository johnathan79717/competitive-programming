class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0) return -1;
        if(A[0] <= A[n-1]) return binary(A, n, target);
        int ans = search(A + n / 2, n - n / 2, target);
        if(ans >= 0) return ans + n / 2;
        return search(A, n / 2, target);
    }
    int binary(int A[], int n, int target) {
        int lb = -1, ub = n;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(A[mid] == target)
                return mid;
            else if(A[mid] > target)
                ub = mid;
            else
                lb = mid;
        }
        return -1;
    }
};