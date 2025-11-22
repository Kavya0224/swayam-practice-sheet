class Solution {
public:
    int numDistinct(string s, string t) {
         int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // Base cases
    for(int r = 0; r <= n; r++) dp[r][0] = 1;  // Empty target
    for(int c = 1; c <= m; c++) dp[0][c] = 0;  // Empty source
    
    // Fill DP table
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            if (s[r-1] == t[c-1]) 
                dp[r][c] = (long long)dp[r-1][c-1] + dp[r-1][c];
            else 
                dp[r][c] = dp[r-1][c];
        }
    }
    
    return dp[n][m];
    }
};