/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
        if(!root) return 0;
        int dontRob = rob(root -> left) + rob(root -> right), robRoot = root -> val;
        if(root -> left) robRoot += rob(root -> left -> left) + rob(root -> left -> right);
        if(root -> right) robRoot += rob(root -> right -> left) + rob(root -> right -> right);
        return max(dontRob, robRoot);
    }
}; *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<int>> dp;
    int rob(TreeNode* root, bool canRob = true) {
        if(!root) return 0;
        if(dp.count(root) && dp[root][canRob] != -1) return dp[root][canRob];
        dp[root] = {-1,-1};
        int dontRob = rob(root -> left, true) + rob(root -> right, true);
        int robRoot = canRob ? root -> val + rob(root -> left, false) + rob(root -> right, false) : -1;
        return dp[root][canRob] = max(dontRob, robRoot);
    }
};