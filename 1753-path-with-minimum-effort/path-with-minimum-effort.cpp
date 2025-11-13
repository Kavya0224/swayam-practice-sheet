class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0, {0,0}});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            int diff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if (i == n - 1 && j == m - 1)
                return diff;

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && y >= 0 && x < n && y < m) {
                    int newDiff = max(diff, abs(heights[x][y] - heights[i][j]));
                    if (newDiff < dist[x][y]) {
                        dist[x][y] = newDiff;
                        pq.push({newDiff, {x, y}});
                    }
                }
            }
        }
        return 0;
    }
};
