class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n; i++)
            while(1 <= A[i] && A[i] <= n)
                if(A[A[i] - 1] != A[i])
                    swap(A[A[i] - 1], A[i]);
                else
                    break;
        for(int i = 0; i < n; i++)
            if(A[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};