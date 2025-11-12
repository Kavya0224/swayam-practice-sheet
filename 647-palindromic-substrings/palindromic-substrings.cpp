class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        
        // dp[i][j] = true if substring s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        int count = 0; // to count all palindromic substrings
        
        // Fill the DP table from bottom to top
        // because dp[i][j] depends on dp[i+1][j-1]
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                // Case 1: Single character (always a palindrome)
                if (i == j) {
                    dp[i][j] = true;
                }
                // Case 2: Two consecutive characters
                // s[i..j] is palindrome if both characters are same
                else if (j == i + 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                // Case 3: More than two characters
                // s[i..j] is palindrome if:
                //   1. The first and last characters match
                //   2. The substring inside (s[i+1..j-1]) is also a palindrome
                else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                // If s[i..j] is a palindrome, increment count
                if (dp[i][j]) {
                    count++;
                }
            }
        }

        // Return total number of palindromic substrings
        return count;
    }
};
