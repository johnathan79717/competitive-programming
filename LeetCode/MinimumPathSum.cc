class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(i == 0 && j == 0)
                    continue;
                if(i == 0 && j > 0)
                    grid[i][j] += grid[i][j-1];
                else if(j == 0 && i > 0)
                    grid[i][j] += grid[i-1][j];
                else {
                    grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
                }
            }
        }
        return grid.back().back();
    }
};