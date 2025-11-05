class Solution {
public:
    int m, n;  // grid dimensions

    // Directions: up, down, left, right
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    // DFS helper to collect maximum gold starting from (x, y)
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int gold = grid[x][y]; // collect gold from current cell
        grid[x][y] = 0;        // mark this cell as visited (avoid revisiting)
        int maxGold = 0;       // track the best gold from this path

        // Explore all 4 possible directions
        for (auto& d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];

            // Move only if next cell is inside the grid and has gold
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
                maxGold = max(maxGold, dfs(grid, nx, ny)); // explore further
            }
        }

        grid[x][y] = gold; // backtrack: restore cell for future paths
        return gold + maxGold; // return total gold collected along this path
    }

    // Main function to get the maximum gold collectable
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxTotal = 0; // result variable

        // Try starting DFS from every cell that has gold
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) { // only start from cells with gold
                    maxTotal = max(maxTotal, dfs(grid, i, j));
                }
            }
        }

        return maxTotal; // return the best result found
    }
};
