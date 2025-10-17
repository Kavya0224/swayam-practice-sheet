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
    // Helper function to perform BFS (level order traversal)
    void bFS(TreeNode* root, vector<vector<int>> &res) {
        queue<TreeNode*> q;
        q.push(root);  // Start with the root node
        
        while (!q.empty()) {
            int n = q.size();  // Number of nodes at the current level
            vector<int> v;     // Vector to store current level's values

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();  // Get the front node in the queue
                q.pop();                     // Remove it from the queue

                if (temp != NULL) {
                    v.push_back(temp->val);  // Add node's value to the current level vector

                    // Add the left and right children to the queue for next level
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
            }

            // Add the current level's values to the result if not empty
            if (!v.empty())
                res.push_back(v);
        }
    }

    // Main function to return level order traversal as a 2D vector
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bFS(root, res);  // Call the BFS helper
        return res;
    }
};
