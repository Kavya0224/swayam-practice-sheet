class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D DP table of size m x n
        // dp[i][j] represents the number of unique paths to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // Base case:
        // The first row (i = 0) and the first column (j = 0)
        // each have only one possible path — moving only right or only down.
        // So we initialized all cells with 1 above.

        // Fill the DP table starting from cell (1,1)
        for (int i = 1; i < m; i++) {          // loop over rows
            for (int j = 1; j < n; j++) {      // loop over columns
                // Number of ways to reach cell (i, j) =
                // ways from the top (i-1, j) + ways from the left (i, j-1)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // The bottom-right corner (m-1, n-1) stores
        // the total number of unique paths from start (0,0) to end (m-1,n-1)
        return dp[m - 1][n - 1];
    }
};