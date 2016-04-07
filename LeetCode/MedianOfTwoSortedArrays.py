class Solution:
    # @return a float
    def findMedianSortedArrays(self, A, B):
         n = len(A)
         m = len(B)
         ans = self.get(A, 0, n, B, 0, m, (m+n)/2+1)
         if (m + n) % 2 == 1:
             return ans
         else:
             return (ans + self.get(A, 0, n, B, 0, m, (m+n)/2)) / 2.0
    def get(self, A, a, n, B, b, m, k):
        if n <= 0:
            return B[b+k-1]
        if m <= 0:
            return A[a+k-1]
        if k <= 1:
            return min(A[a], B[b])
        if A[a+n/2] <= B[b+m/2]:
            if n/2 + 1 + m/2 >= k:
                return self.get(A, a, n, B, b, m/2, k)
            else:
                return self.get(A, a + n/2 + 1, n - (n/2 + 1), B, b, m, k - (n/2 + 1))
        else:
            if m/2 + 1 + n/2 >= k :
                return self.get(A, a, n/2, B, b, m, k)
            else:
                return self.get(A, a, n, B, b + m/2 + 1, m - (m/2 + 1), k - (m/2 + 1))