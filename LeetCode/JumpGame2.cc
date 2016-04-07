class Solution {
public:
    int jump(int A[], int n) {
        vector<int> steps(1, 0);
        for(int i = 0; i < n; i++)
            while(min(i + A[i], n-1) >= steps.size())
                steps.push_back(steps[i] + 1);
        return steps[n-1];
    }
};