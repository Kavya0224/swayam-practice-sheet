class Solution {
public:
    // return type changed to long long to avoid truncation
    long long dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& values, int k, int& count) {
        long long sum = values[u]; // long long to hold large sums

        for (int v : adj[u]) {
            if (v == parent) continue;
            sum += dfs(v, u, adj, values, k, count);
        }

        if (sum % k == 0) {
            count++;
            return 0LL; // cut here, return 0 upward
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;
        dfs(0, -1, adj, values, k, count);
        return count;
    }
};
