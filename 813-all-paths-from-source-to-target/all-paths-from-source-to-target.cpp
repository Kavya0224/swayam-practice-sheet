class Solution {
public:
void dfs(vector<vector<int>>& graph,int src,vector<bool>& vis,vector<int>& path,vector<vector<int>>& ans,int n){
    path.push_back(src);
    if(src==n-1){
        ans.push_back(path);
        return;
    }
    
    vis[src]=true;
    for(auto v:graph[src]){
        if(!vis[v]){
            dfs(graph,v,vis,path,ans,n);
            vis[v]=false;
            path.pop_back();
        }
    }
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n);
        vector<int> path;
        vector<vector<int>> ans;
        dfs(graph,0,vis,path,ans,n);
        return ans;
    }
};