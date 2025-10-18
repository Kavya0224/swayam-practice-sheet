#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();         // Number of rows
        int m = matrix[0].size();      // Number of columns

        unordered_set<int> setRows;    // Set to store indices of rows that should be zeroed
        unordered_set<int> setColumns; // Set to store indices of columns that should be zeroed

        // First pass: identify all rows and columns that contain at least one zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    setRows.insert(i);    // Mark row for zeroing
                    setColumns.insert(j); // Mark column for zeroing
                }
            }
        }

        // Second pass: set elements to zero if their row or column is marked
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (setRows.count(i) > 0 || setColumns.count(j) > 0) {
                    matrix[i][j] = 0; // Zero out the cell
                }
            }
        }
    }
};
