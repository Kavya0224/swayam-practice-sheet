class Solution {
public:
    // Detect cycle using DFS
    bool dfs(int src, vector<bool>& vis, vector<bool>& rec, vector<vector<int>>& edge) {
        vis[src] = true;
        rec[src] = true;

        for (int i = 0; i < edge.size(); i++) {
            int u = edge[i][1];  // prerequisite
            int v = edge[i][0];  // course
            if (u == src) {
                if (!vis[v] && dfs(v, vis, rec, edge)) 
                    return true;
                else if (rec[v]) 
                    return true;
            }
        }

        rec[src] = false;
        return false;
    }

    // Topological sort
    void topo(stack<int>& s, vector<bool>& vis, int src, vector<vector<int>>& edge) {
        vis[src] = true;
        for (int i = 0; i < edge.size(); i++) {
            int u = edge[i][1];
            int v = edge[i][0];
            if (u == src) {
                if (!vis[v]) 
                    topo(s, vis, v, edge);
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);
        stack<int> s;
        vector<int> ans;

        // Step 1: Detect cycle
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, rec, prerequisites)) 
                    return {}; // cycle found → return empty
            }
        }

        // Step 2: Topological sort
        fill(vis.begin(), vis.end(), false); // reset visited

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                topo(s, vis, i, prerequisites);
            }
        }

        // Step 3: Build answer
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};