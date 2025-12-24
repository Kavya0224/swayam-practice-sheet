class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();        // Number of rows
        int n = grid[0].size();     // Number of columns

        // Traverse each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip the starting point (top-left corner)
                if (i == 0 && j == 0) continue;

                // If in the first row, can only come from the left
                if (i == 0) {
                    grid[i][j] += grid[i][j - 1];
                }
                // If in the first column, can only come from above
                else if (j == 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                // Otherwise, choose the smaller path (top or left)
                else {
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }

        // The bottom-right cell now contains the minimum path sum
        return grid[m - 1][n - 1];
    }
};