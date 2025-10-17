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
    // Function to compute the maximum depth (height) of the binary tree
    int maxDepth(TreeNode* root) {
        // Base case: if the node is null, the depth is 0
        if (root == NULL) {
            return 0;
        }

        // Recursively find the depth of the left subtree
        int Leftht = maxDepth(root->left);

        // Recursively find the depth of the right subtree
        int Rightht = maxDepth(root->right);

        // The depth of the current node is 1 (itself) + the greater of the two subtree depths
        return max(Leftht, Rightht) + 1;
    }
};
