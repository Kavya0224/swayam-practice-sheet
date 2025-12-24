class Solution {
public:

    void dfs(int node, int parent,vector<vector<int>>&adj,vector<int>&disc,vector<int>&low,vector<vector<int>>&bridge, vector<bool>&visited,int &count){
        disc[node]=low[node]=count;
        visited[node]=1;

        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];
            if(neigh==parent)
            continue;

            else if(visited[neigh]){
                low[node]=min(low[node],disc[neigh]); // FIXED: should be disc[neigh], not low[neigh]
            }

            else{
                count++;
                dfs(neigh,node, adj,disc,low, bridge,visited,count);
                if(low[neigh]>disc[node]){
                    vector<int>temp;
                    temp.push_back(node);
                    temp.push_back(neigh);
                    bridge.push_back(temp);
                }
                low[node]=min(low[node],low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n); // FIXED: Initialize with size n
        
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>bridge;
        vector<int>disc(n);
        vector<int>low(n);
        vector<bool>visited(n,0);
        int count=0;
        dfs(0,-1,adj,disc,low,bridge,visited,count);
        
        return bridge;
    }
};