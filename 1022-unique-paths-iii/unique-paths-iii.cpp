class Solution {
public:
    int m, n;                 // Number of rows (m) and columns (n) in the grid
    int totalEmpty = 0;       // Total number of empty cells + starting cell
    int result = 0;           // Number of valid unique paths

    // DFS function to explore paths
    void dfs(vector<vector<int>>& grid, int r, int c, int count) {
        // If current cell is out of bounds or is an obstacle/visited (-1), return
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -1)
            return;

        // If we reach the ending cell
        if (grid[r][c] == 2) {
            // Check if we have visited all empty cells
            if (count == totalEmpty) 
                result++;   // Found a valid path
            return;
        }

        // Mark current cell as visited
        int temp = grid[r][c];   // Store current value to restore later
        grid[r][c] = -1;         // Mark visited

        // Explore 4 directions: down, up, right, left
        dfs(grid, r+1, c, count+1);
        dfs(grid, r-1, c, count+1);
        dfs(grid, r, c+1, count+1);
        dfs(grid, r, c-1, count+1);

        // Backtrack: unmark the cell so other paths can use it
        grid[r][c] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();         // Number of rows
        n = grid[0].size();      // Number of columns
        int startR, startC;      // Start cell coordinates

        // Count empty cells and find start position
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) totalEmpty++;  // Empty cell
                if (grid[i][j] == 1) {              // Start cell
                    startR = i;
                    startC = j;
                    totalEmpty++;  // Include start cell in totalEmpty
                }
            }
        }

        // Start DFS from the starting cell, with 0 cells visited so far
        dfs(grid, startR, startC, 0);

        return result;  // Return the total number of valid unique paths
    }
};
