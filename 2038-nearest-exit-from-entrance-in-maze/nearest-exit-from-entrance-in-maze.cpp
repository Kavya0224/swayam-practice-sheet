class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // mark visited

        int steps = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int sz = q.size();
            steps++;

            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                for (auto &d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                        continue;

                    if (maze[ni][nj] != '.')
                        continue;

                    if (ni == 0 || ni == n - 1 || nj == 0 || nj == m - 1)
                        return steps;

                    maze[ni][nj] = '+';
                    q.push({ni, nj});
                }
            }
        }

        return -1;
    }
};
