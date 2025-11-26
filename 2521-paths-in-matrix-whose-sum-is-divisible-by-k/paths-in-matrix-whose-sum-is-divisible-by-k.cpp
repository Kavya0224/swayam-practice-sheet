class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 1000000007;

        // dp[i][j] = vector of size k (remainders)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int r = 0; r < k; r++) {
                    if (dp[i][j][r] == 0) continue;

                    int curr = dp[i][j][r];

                    // Move right (i, j+1)
                    if (j + 1 < m) {
                        int nr = (r + grid[i][j+1]) % k;
                        dp[i][j+1][nr] = (dp[i][j+1][nr] + curr) % MOD;
                    }

                    // Move down (i+1, j)
                    if (i + 1 < n) {
                        int nr = (r + grid[i+1][j]) % k;
                        dp[i+1][j][nr] = (dp[i+1][j][nr] + curr) % MOD;
                    }
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};
