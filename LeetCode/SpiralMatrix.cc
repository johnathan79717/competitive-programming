class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(matrix.empty())
            return vector<int>();
        int dr = 0, dc = 1;
        int rmin = 0, rmax = matrix.size() - 1;
        int cmin = 0, cmax = matrix[0].size() - 1;
        int r = 0, c = 0;
        vector<int> ans;
        while(rmin <= rmax && cmin <= cmax) {
            while(r >= rmin && r <= rmax && c >= cmin && c <= cmax) {
                ans.push_back(matrix[r][c]);
                r += dr;
                c += dc;
            }
            
            // move it back into the matrix
            r -= dr;
            c -= dc;
            
            // change direction
            if(dr == 0 && dc == 1) {
                dr = 1;
                dc = 0;
                rmin++;
            } else if (dr == 1 && dc == 0) {
                dr = 0;
                dc = -1;
                cmax--;
            } else if (dr == 0 && dc == -1) {
                dr = -1;
                dc = 0;
                rmax--;
            } else {
                dr = 0;
                dc = 1;
                cmin++;
            }
            
            r += dr;
            c += dc;
        }
        return ans;
    }
};