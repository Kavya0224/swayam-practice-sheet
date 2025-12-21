class Solution {
public:
    void dfs(int i, vector<vector<int>>& isCon, vector<int>& vis) {
        vis[i] = 1;
        for (int j = 0; j < isCon.size(); j++) {
            if (isCon[i][j] == 1 && !vis[j]) {
                dfs(j, isCon, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isCon) {
        int n = isCon.size();
        vector<int> vis(n, 0);
        int ct = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ct++;
                dfs(i, isCon, vis);
            }
        }
        return ct;
    }
};
