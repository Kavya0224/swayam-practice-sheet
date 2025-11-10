class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();        // Number of rows
        int m = grid[0].size();     // Number of columns

        queue<pair<pair<int,int>, int>> q; // {{i,j}, time}
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Track visited cells

        // Step 1: Push all initially rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark as rotten
                }
            }
        }

        int ans = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        // Step 2: BFS traversal
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            ans = max(ans, t);

            // Explore 4-directional neighbors
            for (int k = 0; k < 4; k++) {
                int ni = i + drow[k];
                int nj = j + dcol[k];

                // Check boundaries and if the neighbor is a fresh orange
                if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1 && vis[ni][nj] != 2) {
                    grid[ni][nj] = 2; // It becomes rotten
                    vis[ni][nj] = 2;
                    q.push({{ni, nj}, t + 1});
                }
            }
        }

        // Step 3: Check if any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1; // Not all oranges rotted
            }
        }

        return ans;
    }
};
