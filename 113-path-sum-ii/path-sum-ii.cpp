class Solution {
public:
    void dfs(TreeNode* root, int tar, vector<vector<int>>& ans, vector<int>& path) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right && tar == root->val) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        dfs(root->left, tar - root->val, ans, path);
        dfs(root->right, tar - root->val, ans, path);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, ans, path);
        return ans;
    }
};
