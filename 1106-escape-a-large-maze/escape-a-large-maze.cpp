// class Solution {
// public:
// void helper(vector<vector<bool>>& vis,int tr,int tc,int sr,int sc,bool& flag){
//     if(sr<0 || sc<0 || sr>=1000000 || sc>=1000000 || vis[sr][sc]==true){
//         return;
//     }
//     if(sr==tr && sc==tc){
//         flag=true;
//         return;
//     }
//     vis[sr][sc]=true;
//     helper(vis,tr,tc,sr+1,sc,flag);
//     helper(vis,tr,tc,sr-1,sc,flag);
//     helper(vis,tr,tc,sr,sc+1,flag);
//     helper(vis,tr,tc,sr,sc-1,flag);
//     vis[sr][sc]=false;
// }
//     bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
//         vector<vector<bool>> vis(1000000,vector<bool>(1000000,false));
//         for(int i=0;i<blocked.size();i++){
//             int r=blocked[i][0];
//             int c=blocked[i][1];
//             vis[r][c]=true;
//         }
//         bool flag=false;
//         helper(vis,target[0],target[1],source[0],source[1],flag);
//         return flag;
//     }
// };
class Solution {
public:
    // Max number of cells that can be enclosed by 200 blocked cells
    const int LIMIT = 20000;
    const int N = 1000000;

    // Directions: up, down, left, right
    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool bfs(vector<int>& start, vector<int>& finish, unordered_set<long long>& blockedSet) {
        queue<pair<int,int>> q;
        unordered_set<long long> visited;

        auto hash = [&](int r, int c) { return (long long)r * N + c; };

        q.push({start[0], start[1]});
        visited.insert(hash(start[0], start[1]));

        while (!q.empty() && visited.size() <= LIMIT) {
            auto [r, c] = q.front(); q.pop();

            // If we can reach the finish, success
            if (r == finish[0] && c == finish[1]) return true;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                long long key = hash(nr, nc);
                if (nr >= 0 && nr < N && nc >= 0 && nc < N &&
                    !blockedSet.count(key) && !visited.count(key)) {
                    visited.insert(key);
                    q.push({nr, nc});
                }
            }
        }

        // If we explored more than LIMIT cells, it means we’re not enclosed
        return visited.size() > LIMIT;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> blockedSet;
        for (auto& b : blocked) {
            blockedSet.insert((long long)b[0] * N + b[1]);
        }

        // Must check from both sides (source and target)
        return bfs(source, target, blockedSet) && bfs(target, source, blockedSet);
    }
};
