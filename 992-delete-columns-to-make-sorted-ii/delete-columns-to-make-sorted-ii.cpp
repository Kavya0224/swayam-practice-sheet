class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> sorted(n, false); // check whether prev element is equal or less than curr element
        int ct = 0;

        for (int i = 0; i < m; i++) {
            bool bad = false;

            for (int j = 1; j < n; j++) {
                if (!sorted[j] && strs[j-1][i] > strs[j][i]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ct++;  // delete this column
                continue;
            }

            // update sorted pairs
            for (int j = 1; j < n; j++) {
                if (strs[j-1][i] < strs[j][i]) {
                    sorted[j] = true;
                }
            }
        }
        return ct;
    }
};
