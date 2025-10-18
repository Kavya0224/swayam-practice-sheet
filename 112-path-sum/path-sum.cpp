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
    // Function to check if there's a root-to-leaf path in the binary tree
    // such that the sum of the node values equals the target
    bool hasPathSum(TreeNode* root, int target) {
        if (!root) return false;  // Base case: empty node means no path

        // If it's a leaf node, check if the current node's value equals the remaining target
        if (!root->left && !root->right) {
            return target == root->val;
        }

        // Recursively check the left and right subtrees with updated target
        int leftSum = hasPathSum(root->left, target - root->val);
        int rightSum = hasPathSum(root->right, target - root->val);

        // Return true if either subtree has a valid path
        return leftSum || rightSum;
    }
};
