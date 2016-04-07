class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return search(matrix, 0, matrix.size(), target);
    }
    
    bool search(vector<vector<int> > &matrix, int a, int n, int target) {
        if(target < matrix[a][0])
            return false;
        if(n == 1) {
            return searchV(matrix[a], 0, matrix[a].size(), target);
        } else {
            return search(matrix, a, n / 2, target) || search(matrix, a + n / 2, n - n / 2, target);
        }
    }
    
    bool searchV(vector<int> &v, int a, int n, int target) {
        if(target < v[a])
            return false;
        if(n == 1) {
            return v[a] == target;
        } else {
            return searchV(v, a, n / 2, target) || searchV(v, a + n / 2, n - n / 2, target);
        }
    }
};