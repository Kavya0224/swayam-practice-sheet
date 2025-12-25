class Solution {
public:
    // Depth-First Search (DFS) to mark all connected '1's as visited
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m) {
        // Base case: stop if out of bounds, already visited, or water ('0')
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == '0')
            return;

        // Mark the current cell as visited
        vis[i][j] = true;

        // Explore all 4 possible directions (up, left, right, down)
        dfs(grid, vis, i - 1, j, n, m); // Up
        dfs(grid, vis, i, j - 1, n, m); // Left
        dfs(grid, vis, i, j + 1, n, m); // Right
        dfs(grid, vis, i + 1, j, n, m); // Down
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();        // Number of rows
        int m = grid[0].size();     // Number of columns
        int ct = 0;                 // Island count

        // Visited matrix to track visited land cells
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Traverse each cell of the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If a land cell ('1') is not visited yet → new island found
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, vis, i, j, n, m);  // Mark all connected land
                    ct++;                         // Increment island count
                }
            }
        }

        // Return total number of islands found
        return ct;
    }
};