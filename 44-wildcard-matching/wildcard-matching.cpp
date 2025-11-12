class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        // dp[i][j] = true if first i chars of s match first j chars of p
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Empty pattern matches empty string
        dp[0][0] = true;

        // Handle patterns like "*", "**", etc. — they can match empty string
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    // Characters match or '?'
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' can match zero or more characters
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
