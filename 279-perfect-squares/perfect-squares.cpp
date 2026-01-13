class Solution {
public:
    int numSquares(int n) {
        // dp[i] will store the minimum number of perfect squares that sum to i
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // Base case: 0 requires 0 perfect squares

        // Precompute all perfect squares less than or equal to n
        vector<int> squares;
        for (int i = 1; i * i <= n; i++)
            squares.push_back(i * i);

        // Build the DP table from 1 to n
        for (int i = 1; i <= n; i++) {
            // Try every perfect square less than or equal to i
            for (int sq : squares) {
                if (i - sq < 0) 
                    break; // No need to check larger squares

                // Transition relation:
                // If we can make (i - sq) using dp[i - sq] squares,
                // then dp[i] = min(dp[i], dp[i - sq] + 1)
                dp[i] = min(dp[i], dp[i - sq] + 1);
            }
        }

        // The answer for n is stored in dp[n]
        return dp[n];
    }
};