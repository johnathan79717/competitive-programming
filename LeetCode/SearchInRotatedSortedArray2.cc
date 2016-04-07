class Solution {
public:
    bool search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0) return -1;
        if(n == 1) return A[0] == target;
        if(A[0] < A[n-1]) return binary(A, n, target);
        return search(A, n/2, target) || search(A + n / 2, n - n / 2, target);
    }
    bool binary(int A[], int n, int target) {
        int lb = -1, ub = n;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(A[mid] == target)
                return true;
            else if(A[mid] > target)
                ub = mid;
            else
                lb = mid;
        }
        return false;
    }
};