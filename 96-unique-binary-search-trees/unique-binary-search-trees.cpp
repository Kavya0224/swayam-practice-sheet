class Solution {
public:
    int numTrees(int n) {
        // Base case:
        // There is exactly 1 unique BST possible with 0 or 1 node.
        // (Empty tree or single-node tree)
        if (n <= 1) return 1;

        int ans = 0;

        // Consider each number from 1 to n as the root node
        for (int i = 1; i <= n; i++) {
            // Number of unique BSTs for the left subtree = numTrees(i - 1)
            // Number of unique BSTs for the right subtree = numTrees(n - i)
            // Multiply them (Cartesian product) because left and right choices are independent.
            ans += numTrees(i - 1) * numTrees(n - i);
        }

        // Return the total number of unique BSTs possible with n nodes
        return ans;
    }
};