class Solution {
public:
    bool helper(TreeNode* root, TreeNode* subRoot) {
        // both null → match
        if(!root && !subRoot) return true;

        // one null and not the other → not match
        if(!root || !subRoot) return false;

        // values must match + children must match
        return root->val == subRoot->val &&
               helper(root->left, subRoot->left) &&
               helper(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        // if same value, try checking full subtree match
        if(root->val == subRoot->val && helper(root, subRoot))
            return true;

        // otherwise search left or right
        return isSubtree(root->left, subRoot) || 
               isSubtree(root->right, subRoot);
    }
};
