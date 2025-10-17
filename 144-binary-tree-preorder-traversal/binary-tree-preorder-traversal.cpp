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
    // Vector to store the result of the preorder traversal
    vector<int> ans;

    // Function to perform preorder traversal (Root → Left → Right)
    vector<int> preorderTraversal(TreeNode* root) {
        if (root) {
            // Visit the root node
            ans.push_back(root->val);

            // Recursively traverse the left subtree
            preorderTraversal(root->left);

            // Recursively traverse the right subtree
            preorderTraversal(root->right);
        }

        // Return the final traversal result
        return ans;
    }
};
