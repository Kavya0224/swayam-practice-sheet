class Solution {
public:
    void dfs(int u, vector<vector<pair<int,int>>>& adj,
             vector<bool>& vis, int& ct) {
        vis[u] = true;

        for (auto [v, cost] : adj[u]) {
            if (!vis[v]) {
                ct += cost;          // count only if reversal is needed
                dfs(v, adj, vis, ct);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto& e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 1}); // original direction → needs reversal
            adj[v].push_back({u, 0}); // reverse direction → no change
        }

        vector<bool> vis(n, false);
        int ct = 0;

        dfs(0, adj, vis, ct);  // start from city 0 only
        return ct;
    }
};
