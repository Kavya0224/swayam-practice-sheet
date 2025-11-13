class Solution {
public:
    // DFS function to check cycles and mark safe nodes
    bool dfs(int u, vector<bool>& vis, vector<bool>& rec, vector<vector<int>>& adj, vector<bool>& chk) {
        vis[u] = true;      // Mark the current node as visited
        rec[u] = true;      // Add current node to recursion stack
        chk[u] = false;     // Initially mark node as unsafe

        for (int v : adj[u]) {  // Explore all neighbors
            if (!vis[v]) {      // If neighbor is not visited
                if (dfs(v, vis, rec, adj, chk)) {  // Recurse
                    chk[v] = false; // If cycle detected, mark neighbor as unsafe
                    return true;    // Propagate cycle detection
                }
            } 
            else if (rec[v]) {    // If neighbor is in recursion stack, cycle found
                chk[v] = false;   // Mark neighbor as unsafe
                return true;       // Cycle detected
            }
        }

        chk[u] = true;   // No cycle found from this node; mark as safe
        rec[u] = false;  // Remove node from recursion stack
        return false;    // No cycle detected in this path
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> chk(V, false);   // Marks if a node is safe (true) or unsafe (false)
        vector<bool> vis(V, false);   // Marks if a node has been visited
        vector<bool> rec(V, false);   // Marks nodes in the recursion stack

        // Run DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, rec, graph, chk);
            }
        }

        vector<int> ans;
        // Collect all nodes marked safe
        for (int i = 0; i < V; i++) {
            if (chk[i] == true) ans.push_back(i);
        }

        return ans;  // Return list of eventual safe nodes
    }
};
