class Solution {
public:
bool dfs(int u,vector<bool>& vis,vector<bool>& rec,vector<vector<int>>& adj,vector<bool>& chk){
      vis[u]=true;
      rec[u]=true;
      chk[u]=false;
      for(int v:adj[u]){
          if(!vis[v]){
              if(dfs(v,vis,rec,adj,chk)){
                  chk[v]=false;
                  return true;
              } 
              
          }
          else if(rec[v]){
              chk[v]=false;
                  return true;
          }
      }
      chk[u]=true;
      rec[u]=false;
      return false;
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool> chk(V,false);
        vector<bool> vis(V,false);
        vector<bool> rec(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,rec,graph,chk);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(chk[i]==true) ans.push_back(i);
        }
        return ans;
    }
};