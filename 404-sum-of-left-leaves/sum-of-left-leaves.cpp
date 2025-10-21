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
    // Helper function to recursively traverse the tree
    // isLeft indicates whether the current node is a left child
    void helper(TreeNode* root, int& sum, bool isLeft) {
        if (!root) return; // Base case: null node

        // If it's a leaf node and it's a left child, add its value to sum
        if (!root->left && !root->right && isLeft) {
            sum += root->val;
            return;
        }

        // Recurse on the left child and mark it as a left child
        helper(root->left, sum, true);

        // Recurse on the right child and mark it as not a left child
        helper(root->right, sum, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum, false); // Root is not considered a left child
        return sum;
    }
};
