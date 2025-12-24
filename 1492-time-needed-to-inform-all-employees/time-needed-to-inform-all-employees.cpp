class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({headID,informTime[headID]});
        int time=0;
        while(!q.empty()){
            int head=q.front().first;
            int curr=q.front().second;
            q.pop();
            time=max(time,curr);
            for(int u:adj[head]){
                q.push({u,curr+informTime[u]});
            }
        }
        return time;

    }
};