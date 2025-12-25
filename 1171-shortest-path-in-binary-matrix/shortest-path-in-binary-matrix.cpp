class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() - 1;
        int m = grid[0].size() - 1;

        if (grid[0][0] == 1 || grid[n][m] == 1)
            return -1;

        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0}, 1});
        grid[0][0] = 1; // mark visited

        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if (i == n && j == m)
                return dist;

            // top-right
            if (i - 1 >= 0 && j + 1 <= m && grid[i-1][j+1] == 0) {
                q.push({{i-1, j+1}, dist + 1});
                grid[i-1][j+1] = 1;
            }

            // top
            if (i - 1 >= 0 && grid[i-1][j] == 0) {
                q.push({{i-1, j}, dist + 1});
                grid[i-1][j] = 1;
            }

            // bottom-left
            if (i + 1 <= n && j - 1 >= 0 && grid[i+1][j-1] == 0) {
                q.push({{i+1, j-1}, dist + 1});
                grid[i+1][j-1] = 1;
            }

            // left
            if (j - 1 >= 0 && grid[i][j-1] == 0) {
                q.push({{i, j-1}, dist + 1});
                grid[i][j-1] = 1;
            }

            // right
            if (j + 1 <= m && grid[i][j+1] == 0) {
                q.push({{i, j+1}, dist + 1});
                grid[i][j+1] = 1;
            }

            // top-left
            if (i - 1 >= 0 && j - 1 >= 0 && grid[i-1][j-1] == 0) {
                q.push({{i-1, j-1}, dist + 1});
                grid[i-1][j-1] = 1;
            }

            // bottom
            if (i + 1 <= n && grid[i+1][j] == 0) {
                q.push({{i+1, j}, dist + 1});
                grid[i+1][j] = 1;
            }

            // bottom-right
            if (i + 1 <= n && j + 1 <= m && grid[i+1][j+1] == 0) {
                q.push({{i+1, j+1}, dist + 1});
                grid[i+1][j+1] = 1;
            }
        }

        return -1;
    }
};