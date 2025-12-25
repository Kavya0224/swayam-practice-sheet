class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    // vis[i][j]=true;
                }
            }
           
        }
        while(q.size()>0){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            vis[i][j]=true;
            mat[i][j]=dist;
            if(i-1>=0 && !vis[i-1][j] && mat[i-1][j]!=0){
                q.push({{i-1,j},dist+1});
                vis[i-1][j]=true;
            }
            if(i+1<n && !vis[i+1][j] && mat[i+1][j]!=0){
                q.push({{i+1,j},dist+1});
                vis[i+1][j]=true;
            }
            if(j-1>=0 && !vis[i][j-1] && mat[i][j-1]!=0){
                q.push({{i,j-1},dist+1});
                vis[i][j-1]=true;
            }
            if(j+1<m && !vis[i][j+1] && mat[i][j+1]!=0){
                q.push({{i,j+1},dist+1});
                vis[i][j+1]=true;
            }
        }
        return mat;
    }
};