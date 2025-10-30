class Solution {
public:
    void helper(int n, vector<int>& ans, int i) {
        if(i > n) return; // compute up to n

        if(i % 2 == 0){
            ans.push_back(ans[i / 2]);
        } else {
            ans.push_back(ans[i / 2] + 1);
        }

        helper(n, ans, i + 1);
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0); // bits for 0

        if(n == 0) return ans;

        helper(n, ans, 1); // start from 1
        return ans;
    }
};
