class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int cutA = m/2, cutB = n/2;
        if(m <= 2 || n <= 2) {
            vector<int> v;
            for(int i = 0; i < m; i++)
                v.push_back(A[i]);
            for(int i = 0; i < n; i++)
                v.push_back(B[i]);
            sort(v.begin(), v.end());
            if((m + n) % 2)
                return v[(m+n)/2];
            else
                return double(v[(m+n)/2] + v[(m+n)/2-1])/2;
        }
            
        if(m % 2 == 0 && n % 2 == 0)
            cutA--;
        if(A[cutA] < B[cutB]) {
            int discard = min(cutA, n - 1 - cutB);
            return findMedianSortedArrays(A + discard, m - discard, B, n - discard);
        } else if(A[cutA] > B[cutB]) {
            int discard = min(m - 1 - cutA, cutB);
            return findMedianSortedArrays(A, m - discard, B + discard, n - discard);
        } else {
            return A[cutA];
        }
    }
};