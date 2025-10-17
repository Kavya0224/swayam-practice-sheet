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
    // Vector to store the result of postorder traversal
    vector<int> ans;

    // Function to perform postorder traversal (Left → Right → Root)
    vector<int> postorderTraversal(TreeNode* root) {
        if (root) {
            // Recursively traverse the left subtree
            postorderTraversal(root->left);

            // Recursively traverse the right subtree
            postorderTraversal(root->right);

            // Visit the root node
            ans.push_back(root->val);
        }

        // Return the result vector
        return ans;
    }
};
