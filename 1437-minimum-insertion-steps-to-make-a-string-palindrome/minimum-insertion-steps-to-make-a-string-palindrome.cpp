class Solution {
public:
    int minInsertions(string s) {
        // Step 1: Create a reversed copy of the string
        // This will help us compute the Longest Palindromic Subsequence (LPS)
        string rev = s;
        int n = s.length();
        reverse(rev.begin(), rev.end());
        
        // Step 2: Create a DP table for LCS (Longest Common Subsequence)
        // dp[i][j] = length of LCS between s[0..i-1] and rev[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Step 3: Build the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                
                // If characters match, extend the previous LCS by 1
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                // If they don't match, take the maximum LCS by ignoring
                // either the current character from s or rev
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Step 4: The length of the longest palindromic subsequence is dp[n][n]
        // Minimum insertions required = total length - length of LPS
        return n - dp[n][n];
    }
};