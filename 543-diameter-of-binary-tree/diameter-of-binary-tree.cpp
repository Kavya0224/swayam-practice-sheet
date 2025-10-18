class Solution {
    int res = 0;  // Stores the maximum diameter found so far

public:
    // Main function to compute the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);  // Start DFS traversal from the root
        return res; // The result holds the diameter
    }

private:
    // Depth-First Search helper function
    // Returns the height of the tree rooted at 'root'
    int dfs(TreeNode* root) {
        if (!root) {
            return 0; // Base case: empty node has height 0
        }

        int l = dfs(root->left);   // Height of left subtree
        int r = dfs(root->right);  // Height of right subtree

        res = max(res, l + r);     // Update diameter if longer path found

        return 1 + max(l, r);      // Return height of current subtree
    }    
};
