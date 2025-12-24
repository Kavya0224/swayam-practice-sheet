class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        if (m == 0) return 0;

        // If start or end is blocked, no path
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
            return 0;

        // dp[i][j] = number of ways to reach cell (i,j)
        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        // Starting cell
        dp[0][0] = 1;

        // First column: only downward moves from above possible
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[i][0] == 0 && dp[i-1][0] > 0)
                dp[i][0] = 1;
            else
                dp[i][0] = 0;
        }

        // First row: only rightward moves from left possible
        for (int j = 1; j < m; j++) {
            if (obstacleGrid[0][j] == 0 && dp[0][j-1] > 0)
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }

        // Fill the rest of dp table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;  // obstacle blocks path
                }
            }
        }

        return (int) dp[n-1][m-1];
    }
};