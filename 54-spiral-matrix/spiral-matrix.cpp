class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();          // Total number of rows
        int m = mat[0].size();       // Total number of columns
        int strow = 0;               // Starting row index
        int stcol = 0;               // Starting column index
        int erow = n - 1;            // Ending row index
        int ecol = m - 1;            // Ending column index
        vector<int> ans;             // Result vector to store spiral order

        // Loop until we traverse all layers
        while (strow <= erow && stcol <= ecol) {

            // Traverse top row from left to right
            for (int i = stcol; i <= ecol; i++) {
                ans.push_back(mat[strow][i]);
            }

            // Traverse rightmost column from top to bottom
            for (int i = strow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }

            // Traverse bottom row from right to left (only if multiple rows exist)
            for (int i = ecol - 1; i >= stcol; i--) {
                if (strow == erow) {
                    break; // Avoid double traversal of single row
                }
                ans.push_back(mat[erow][i]);
            }

            // Traverse leftmost column from bottom to top (only if multiple columns exist)
            for (int i = erow - 1; i >= strow + 1; i--) {
                if (stcol == ecol) {
                    break; // Avoid double traversal of single column
                }
                ans.push_back(mat[i][stcol]);
            }

            // Move towards the inner layer
            strow++;
            stcol++;
            erow--;
            ecol--;
        }

        return ans; // Return the spiral ordered list
    }
};
