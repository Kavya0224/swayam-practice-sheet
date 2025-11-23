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
void helper(TreeNode* root,int path,vector<int>& ans){
    if(!root) return;
     path=path*10+root->val; //intially path=0
    if(!root->left && !root->right){
        ans.push_back(path);
        return;
    }
   
    helper(root->left,path,ans);
    helper(root->right,path,ans);

}
    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        helper(root,0,ans);
        int sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
        }
        return sum;
        
    }
};