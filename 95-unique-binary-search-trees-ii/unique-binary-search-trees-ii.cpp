class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        if (start > end)
            return {nullptr};

        vector<TreeNode*> result;

        for (int root = start; root <= end; ++root) {
            vector<TreeNode*> leftTrees = generate(start, root - 1);
            vector<TreeNode*> rightTrees = generate(root + 1, end);

            for (auto l : leftTrees) {
                for (auto r : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};
