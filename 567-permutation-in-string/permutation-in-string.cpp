class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        // If s1 is longer than s2, it's impossible for s2 to contain a permutation of s1
        if (n > m) return false;

        // Sort s1 once — this represents the "canonical" order of its characters
        string sortedS1 = s1;
        sort(sortedS1.begin(), sortedS1.end());

        // Slide a window of length n across s2
        for (int i = 0; i <= m - n; i++) {
            // Extract substring of size n from s2 starting at index i
            string sub = s2.substr(i, n);

            // Sort the substring to compare with sorted s1
            sort(sub.begin(), sub.end());

            // If sorted substring matches sorted s1, we found a permutation
            if (sub == sortedS1) return true;
        }

        // If no matching permutation found
        return false;
    }
};
