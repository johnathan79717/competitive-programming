class Solution {
public:
    // void merge(int A[], int m, int B[], int n) {
    //     copy(B, B + n, A + m);
    //     inplace_merge(A, A + m, A + m + n);
    // }
    void merge(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(i >= 0 && j >= 0) {
            if(A[i] > B[j])
                A[k--] = A[i--];
            else
                A[k--] = B[j--];
        }
        while(j >= 0)
            A[k--] = B[j--];        
    }
};