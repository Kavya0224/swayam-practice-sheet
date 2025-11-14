class Solution {
public:
    int minInsertions(string s) {
        string rev = s;
        int n = s.length();
        reverse(rev.begin(), rev.end());
        
        // dp[i][j] will store the length of the longest common subsequence
        // between s[0..i-1] and rev[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Build the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                
                // If characters match, add 1 to the result of the previous substring
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                // Otherwise, take the maximum of ignoring one character from either string
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The bottom-right cell contains the length of the longest palindromic subsequence
        return n-dp[n][n];
    }
};