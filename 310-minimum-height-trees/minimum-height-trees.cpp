class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // push all leaves
        for (int i = 0; i < n; i++)
            if (degree[i] == 1)
                q.push(i);

        int remaining = n;

        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;

            while (sz--) {
                int leaf = q.front();
                q.pop();

                for (int nei : adj[leaf]) {
                    degree[nei]--;
                    if (degree[nei] == 1)
                        q.push(nei);
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
