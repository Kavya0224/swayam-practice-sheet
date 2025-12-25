class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(board[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                }
            }
        }
        while(q.size()>0){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            vis[i][j]=true;
             if(i-1>=0 && !vis[i-1][j] && board[i-1][j]!=0){
                q.push({i-1,j});
                vis[i-1][j]=true;
            }
            if(i+1<n && !vis[i+1][j] && board[i+1][j]!=0){
                q.push({i+1,j});
                vis[i+1][j]=true;
            }
            if(j-1>=0 && !vis[i][j-1] && board[i][j-1]!=0){
                q.push({i,j-1});
                vis[i][j-1]=true;
            }
            if(j+1<m && !vis[i][j+1] && board[i][j+1]!=0){
                q.push({i,j+1});
                vis[i][j+1]=true;
            }
        }
        int ct=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]==1 && !vis[i][j]){
                    ct++;
                }
            }
        }
        return ct;
    }
};