class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        // For each column y:
        //   minRow[y] = smallest x where a building exists in column y
        //   maxRow[y] = largest  x where a building exists in column y
        vector<int> minRow(n + 1, n + 1);
        vector<int> maxRow(n + 1, 0);

        // For each row x:
        //   minCol[x] = smallest y where a building exists in row x
        //   maxCol[x] = largest  y where a building exists in row x
        vector<int> minCol(n + 1, n + 1);
        vector<int> maxCol(n + 1, 0);

        // Step 1: Record min/max building positions for every row and column
        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            // Updating columns
            minRow[y] = min(minRow[y], x);
            maxRow[y] = max(maxRow[y], x);

            // Updating rows
            minCol[x] = min(minCol[x], y);
            maxCol[x] = max(maxCol[x], y);
        }

        int coveredCount = 0;

        // Step 2: Check each building if it’s covered from all 4 directions
        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            bool hasUp    = (minRow[y] < x);  // a building exists above
            bool hasDown  = (x < maxRow[y]);  // a building exists below
            bool hasLeft  = (minCol[x] < y);  // a building exists to the left
            bool hasRight = (y < maxCol[x]);  // a building exists to the right

            if (hasUp && hasDown && hasLeft && hasRight) {
                coveredCount++;
            }
        }

        return coveredCount;
    }
};
