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
    // Vector to store the result of inorder traversal
    vector<int> ans;

    // Function to perform inorder traversal (Left → Root → Right)
    vector<int> inorderTraversal(TreeNode* root) {
        if (root) {
            // Recursively traverse the left subtree
            inorderTraversal(root->left);

            // Visit the root node
            ans.push_back(root->val);

            // Recursively traverse the right subtree
            inorderTraversal(root->right);
        }

        // Return the result vector
        return ans;
    }
};
