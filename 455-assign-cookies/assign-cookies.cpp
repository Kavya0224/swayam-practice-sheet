class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factors and cookie sizes in ascending order
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0; // Pointer for children (greed factors)
        int j = 0; // Pointer for cookies (sizes)
        int n = g.size();
        int m = s.size();
        int ct = 0; // Count of content children
        
        // Use two-pointer approach to match children and cookies
        while (i < n && j < m) {
            // If the current cookie can satisfy the current child's greed
            if (s[j] >= g[i]) {
                ct++;   // One more child is content
                i++;    // Move to the next child
                j++;    // Move to the next cookie
            } else {
                // Current cookie too small, try the next larger cookie
                j++;
            }
        }
        
        // Return total number of content children
        return ct;
    }
};
