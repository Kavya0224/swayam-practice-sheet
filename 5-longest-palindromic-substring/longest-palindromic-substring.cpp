class Solution {
public:
    string longestPalindrome(string s) {
        // If the string has 0 or 1 character, it's already a palindrome
        if (s.length() <= 1) {
            return s;
        }
        
        int max_len = 1;  // Length of the longest palindrome found
        int start = 0;    // Starting index of the longest palindrome
        int end = 0;      // Ending index of the longest palindrome

        // dp[i][j] will be true if the substring s[i...j] is a palindrome
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        
        // Iterate through all possible end indices (i)
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;  // Every single character is a palindrome by itself

            // Check all possible start indices (j) before i
            for (int j = 0; j < i; ++j) {
                // A substring s[j...i] is a palindrome if:
                // 1. The characters at both ends match (s[j] == s[i]), and
                // 2. The inside substring s[j+1...i-1] is a palindrome (dp[j+1][i-1] == true),
                //    OR the substring length is 2 or 3 (i - j <= 2)
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;  // Mark this substring as a palindrome

                    // Update the longest palindrome if the current one is longer
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        
        // Return the longest palindromic substring found
        return s.substr(start, end - start + 1);
    }
};
