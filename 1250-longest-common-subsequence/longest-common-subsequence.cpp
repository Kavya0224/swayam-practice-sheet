class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i] will store the length of the longest common subsequence (LCS)
        // that ends at text1[i] for the portion of text2 processed so far.
        vector<int> dp(text1.length(), 0);

        // Tracks the overall longest LCS length found
        int longest = 0;

        // Iterate through each character in text2
        for (char c : text2) {
            int curLength = 0; // Holds the maximum LCS length up to the current point in text1

            // Compare current character from text2 with all characters of text1
            for (int i = 0; i < dp.size(); i++) {
                // If we find a longer LCS so far, update curLength
                if (curLength < dp[i]) {
                    curLength = dp[i];
                }
                // If characters match, we can extend the previous subsequence by 1
                else if (c == text1[i]) {
                    dp[i] = curLength + 1;           // Update dp[i] with new LCS length
                    longest = max(longest, dp[i]);   // Track the global maximum
                }
            }
        }

        // Return the length of the longest common subsequence found
        return longest;        
    }
};
