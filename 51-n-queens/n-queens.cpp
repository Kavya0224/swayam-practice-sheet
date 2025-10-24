class Solution {
public: 

    // Function to check if placing a Queen at position (row, col) is safe
    bool isSafe(vector<string>& board, int n, int row, int col) {

        // Check the current row for any Queen
        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }

        // Check the current column for any Queen
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check the upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check the upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // If no conflicts found, the position is safe
        return true;
    }

    // Recursive helper function to place queens row by row
    void helper(vector<vector<string>>& ans, int n, int row, vector<string>& board) {
        // Base case: all rows are filled, store the current board configuration
        if (row == n) {
            ans.push_back({board});
            return;
        }

        // Try placing a Queen in each column of the current row
        for (int j = 0; j < n; j++) {
            if (isSafe(board, n, row, j)) {
                // Place the Queen
                board[row][j] = 'Q';
                // Move to the next row recursively
                helper(ans, n, row + 1, board);
                // Backtrack: remove the Queen and try the next column
                board[row][j] = '.';
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        // Initialize an empty board with all positions marked as '.'
        vector<string> board(n, string(n, '.'));

        // To store all possible solutions
        vector<vector<string>> ans;

        // Start placing queens from the first row
        helper(ans, n, 0, board);

        // Return all valid configurations
        return ans;
    }
};
