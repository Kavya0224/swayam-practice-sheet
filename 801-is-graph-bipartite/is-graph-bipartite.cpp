class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1 = uncolored, 0 = color A, 1 = color B

        // We need to check all components (graph may be disconnected)
        for (int start = 0; start < n; ++start) {
            if (color[start] != -1) continue;  // already colored, skip

            queue<int> q;
            q.push(start);
            color[start] = 0;  // start coloring this component

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    // If neighbor is uncolored, color it with the opposite color
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    // If neighbor has the same color, graph is not bipartite
                    else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }

        return true;  // No conflicts found → bipartite
    }
};
