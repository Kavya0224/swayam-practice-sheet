class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        unordered_map<int, int> levelSum;
        int mx = INT_MIN;
        int ansLevel = 1;

        while (!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();

            levelSum[lvl] += node->val;

            

            if (node->left)
                q.push({node->left, lvl + 1});
            if (node->right)
                q.push({node->right, lvl + 1});
        }
        for (auto mp : levelSum) {
        if (mp.second > mx) {
        mx = mp.second;
        ansLevel = mp.first;
    }
    else if(mp.second==mx){
        ansLevel=min(ansLevel,mp.first);
    }
}


        return ansLevel;
    }
};
