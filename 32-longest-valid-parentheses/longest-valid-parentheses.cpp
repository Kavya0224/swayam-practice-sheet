class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                // Case 1: "()" pattern
                if (s[i-1] == '(') {
                    dp[i] = 2 + (i >= 2 ? dp[i-2] : 0);
                } 
                // Case 2: "))" and previous valid substring can extend
                else {
                    int j = i - dp[i-1] - 1;
                    if (j >= 0 && s[j] == '(') {
                        dp[i] = dp[i-1] + 2 + (j >= 1 ? dp[j-1] : 0);
                    }
                }
                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};
