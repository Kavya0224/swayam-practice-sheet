class Solution {
public:
    int n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& grid, queue<pair<int,int>>& q) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return;

        grid[i][j] = 2;          // mark first island
        q.push({i, j});          // store for BFS

        for (auto &d : dir)
            dfs(i + d[0], j + d[1], grid, q);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int,int>> q;
        bool found = false;

        // Step 1: Find and mark first island
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, q);
                    found = true;
                }
            }
        }

        // Step 2: BFS to reach second island
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto &d : dir) {
                    int nx = x + d[0], ny = y + d[1];

                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;

                    if (grid[nx][ny] == 1)
                        return steps;     // reached second island

                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
