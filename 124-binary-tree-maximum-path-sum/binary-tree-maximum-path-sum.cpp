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
    int dfs(TreeNode* root,int& ans){
        if(root==NULL) return 0;
        int lf=max(0,dfs(root->left,ans));
        int rht=max(0,dfs(root->right,ans));
        ans=max(ans,lf+rht+root->val);
        return max(lf,rht)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        dfs(root,ans);
        return ans;
    }
};