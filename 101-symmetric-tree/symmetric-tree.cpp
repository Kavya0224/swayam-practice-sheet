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
    // Public method to check if a binary tree is symmetric
    bool isSymmetric(TreeNode* root) {
        // A tree is symmetric if its left and right subtrees are mirror images
        return isMirror(root->left, root->right);
    }

private:
    // Helper function to check if two trees are mirror images of each other
    bool isMirror(TreeNode* n1, TreeNode* n2) {
        // If both nodes are null, they are symmetric (mirror images)
        if (n1 == nullptr && n2 == nullptr) {
            return true;
        }

        // If only one of them is null, they can't be symmetric
        if (n1 == nullptr || n2 == nullptr) {
            return false;
        }

        // Check:
        // - Values at current nodes are equal
        // - Left subtree of n1 is a mirror of right subtree of n2
        // - Right subtree of n1 is a mirror of left subtree of n2
        return (n1->val == n2->val) &&
               isMirror(n1->left, n2->right) &&
               isMirror(n1->right, n2->left);
    }
};
