class Solution {
public:
    bool helper(string &s1, string &s2, string &s3,
                int i, int j, int k, vector<vector<int>> &dp) {
        
        if (k == 0)
            return i == 0 && j == 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool ok = false;

        if (i > 0 && s1[i - 1] == s3[k - 1])
            ok |= helper(s1, s2, s3, i - 1, j, k - 1, dp);

        if (j > 0 && s2[j - 1] == s3[k - 1])
            ok |= helper(s1, s2, s3, i, j - 1, k - 1, dp);

        return dp[i][j] = ok;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int n = s1.size(), m = s2.size(), l = s3.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return helper(s1, s2, s3, n, m, l, dp);
    }
};
