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
    // Function to check if two binary trees are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If either node is null, both must be null to be considered the same
        if (p == NULL || q == NULL) {
            return p == q; // true if both are null, false if only one is null
        }

        // Check current node values and recursively check left and right subtrees
        return isSameTree(p->left, q->left)     // Left subtrees must be the same
            && isSameTree(p->right, q->right)   // Right subtrees must be the same
            && p->val == q->val;                // Current node values must match
    }
};
