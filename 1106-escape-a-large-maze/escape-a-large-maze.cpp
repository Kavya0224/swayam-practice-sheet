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
