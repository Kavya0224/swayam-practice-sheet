/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Function to return the right side view of a binary tree
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;            // Stores the final result: rightmost nodes at each level
        int level = -1;             // Tracks the deepest level visited so far
        traverseRightSide(root, level, 0, ans); // Start traversal from root at level 0
        return ans;
    }

    // Helper function to perform modified DFS (prioritizing right subtree)
    void traverseRightSide(TreeNode* root, int &mainLevel, int level, vector<int>& ans) {
        if (root == NULL) return;  // Base case: if node is null, return

        // If this is the first time reaching this level, add node to result
        if (mainLevel < level) {
            ans.push_back(root->val);             // Capture the rightmost node at this level
            mainLevel = max(mainLevel, level);    // Update the deepest level reached
        }

        // Visit right child first to ensure rightmost nodes are visited before left ones
        traverseRightSide(root->right, mainLevel, level + 1, ans);
        traverseRightSide(root->left, mainLevel, level + 1, ans);
    }
};
