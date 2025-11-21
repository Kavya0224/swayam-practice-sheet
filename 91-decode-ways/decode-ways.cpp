class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;       // empty string
        dp[1] = 1;       // first char already non-zero

        for (int i = 2; i <= n; i++) {
            int one = s[i - 1] - '0';
            int two = (s[i - 2] - '0') * 10 + one;

            // Single digit valid (1-9)
            if (one >= 1)
                dp[i] += dp[i - 1];

            // Two-digit valid (10-26)
            if (two >= 10 && two <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};
