class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();          // Total number of rows in the matrix
        int cols = matrix[0].size();       // Total number of columns in the matrix
        int row = 0;                       // Start from the first row
        int col = cols - 1;                // Start from the last column (top-right corner)

        // Loop until we are within the bounds of the matrix
        while (row < rows && col > -1) {
            int cur = matrix[row][col];    // Current element at position (row, col)

            // If the current element matches the target, return true
            if (cur == target) return true;

            // If the target is greater, move down to the next row
            if (target > cur) row++;

            // If the target is smalreturnler, move left to the previous column
            else col--;
        }

        // Target not found in the matrix
        return false;
    }
};
