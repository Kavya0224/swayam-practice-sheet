class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(vector<vector<int>>& mat, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];

        int best = 1; // minimum path length is 1 (the cell itself)

        for (auto &d : dir) {
            int x = i + d[0];
            int y = j + d[1];

            if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] > mat[i][j]) {
                best = max(best, 1 + dfs(mat, x, y));
            }
        }

        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        dp.assign(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(mat, i, j));
            }
        }
        return ans;
    }
};
