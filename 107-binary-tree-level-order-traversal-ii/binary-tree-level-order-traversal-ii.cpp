class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<vector<int>> ans;

        while(!q.empty()){
            auto [node, dist] = q.front();
            q.pop();

            if (ans.size() <= dist)
                ans.resize(dist + 1);

            ans[dist].push_back(node->val);

            if (node->left) q.push({node->left, dist+1});
            if (node->right) q.push({node->right, dist+1});
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
