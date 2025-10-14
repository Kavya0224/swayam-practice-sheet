class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxRow = 0;   // Row index with the most 1s
        int maxOnes = 0;  // Maximum number of 1s found

        // Iterate through each row
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;

            // Count the number of 1s in the current row
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) count++;
            }

            // Update if this row has more 1s than previously found
            if (count > maxOnes) {
                maxOnes = count;
                maxRow = i;
            }
        }

        // Return the result as a vector: [row_index, max_ones]
        return {maxRow, maxOnes};
    }
};
