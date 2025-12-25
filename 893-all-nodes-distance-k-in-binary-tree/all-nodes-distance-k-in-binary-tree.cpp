/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& par_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                par_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                par_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par_track;
        markParent(root,par_track);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int curr_lvl=0;
        while(!q.empty()){
            int n=q.size();
            if(curr_lvl++==k) break;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                 if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(par_track[curr] && !vis[par_track[curr]]){
                    q.push(par_track[curr]);
                    vis[par_track[curr]]=true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            res.push_back(current->val);
        }
        return res;
    }
};