class Solution {
public:
    // Helper function to compare frequency arrays of size 26 (for lowercase English letters)
    bool is_anagram_freq(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i]) return false;  // If mismatch found, not an anagram
        return true;  // All character frequencies match
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> ans;  // Result vector to store starting indices of anagrams
        if (n < m) return ans;  // If s is shorter than p, no anagrams possible

        vector<int> p_freq(26, 0), window_freq(26, 0);  // Frequency arrays for p and current window in s

        // Build frequency count for string p
        for (char c : p) p_freq[c - 'a']++;

        // Use sliding window of size m over string s
        for (int i = 0; i < n; i++) {
            window_freq[s[i] - 'a']++;  // Add current character to window

            if (i >= m)
                window_freq[s[i - m] - 'a']--;  // Remove character going out of the window

            // Compare current window frequency with p's frequency
            if (is_anagram_freq(window_freq, p_freq))
                ans.push_back(i - m + 1);  // Valid anagram found, store starting index
        }

        return ans;  // Return all starting indices of anagrams of p in s
    }
};
