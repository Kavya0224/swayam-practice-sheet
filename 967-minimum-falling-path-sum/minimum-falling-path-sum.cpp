class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+2, INT_MAX)); // extra column padding for bounds

        // Initialize first row
        for (int j = 1; j <= m; j++) {
            dp[1][j] = mat[0][j-1];
        }

        // Fill DP table
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = mat[i-1][j-1] + min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
            }
        }

        // Find minimum in last row
        int mini = INT_MAX;
        for (int j = 1; j <= m; j++) {
            mini = min(mini, dp[n][j]);
        }
        return mini;
    }
};
