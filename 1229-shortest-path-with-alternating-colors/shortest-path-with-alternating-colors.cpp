class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {
        vector<vector<int>> redAdj(n), blueAdj(n);
        
        for (auto &e : redEdges)
            redAdj[e[0]].push_back(e[1]);
        
        for (auto &e : blueEdges)
            blueAdj[e[0]].push_back(e[1]);

        // dist[node][0] -> last edge was RED
        // dist[node][1] -> last edge was BLUE
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        
        queue<pair<int,int>> q;

        // Start node with both colors
        dist[0][0] = dist[0][1] = 0;
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [u, lastColor] = q.front();
            q.pop();

            if (lastColor == 0) { // last was RED → take BLUE
                for (int v : blueAdj[u]) {
                    if (dist[v][1] == INT_MAX) {
                        dist[v][1] = dist[u][0] + 1;
                        q.push({v, 1});
                    }
                }
            } else { // last was BLUE → take RED
                for (int v : redAdj[u]) {
                    if (dist[v][0] == INT_MAX) {
                        dist[v][0] = dist[u][1] + 1;
                        q.push({v, 0});
                    }
                }
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int best = min(dist[i][0], dist[i][1]);
            ans[i] = (best == INT_MAX ? -1 : best);
        }

        return ans;
    }
};
