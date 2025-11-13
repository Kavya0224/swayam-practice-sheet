class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (!dict.count(endWord)) return ans;

        // Step 1: BFS to find shortest distances and build parent graph
        unordered_map<string, vector<string>> parents; // who can lead to this word
        unordered_map<string, int> dist;               // shortest distance from beginWord
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;
        int wordLen = beginWord.size();

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int step = dist[word];

            for (int i = 0; i < wordLen; i++) {
                string next = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    next[i] = ch;
                    if (!dict.count(next)) continue;

                    if (!dist.count(next)) {
                        dist[next] = step + 1;
                        q.push(next);
                    }
                    // Only record parent if it's on a shortest path
                    if (dist[next] == step + 1)
                        parents[next].push_back(word);
                }
            }
        }

        if (!dist.count(endWord)) return ans; // No path found

        // Step 2: DFS/backtracking to reconstruct paths
        vector<string> path = {endWord};
        dfs(endWord, beginWord, parents, path, ans);
        for (auto &v : ans) reverse(v.begin(), v.end());
        return ans;
    }

private:
    void dfs(const string &word, const string &beginWord,
             unordered_map<string, vector<string>> &parents,
             vector<string> &path, vector<vector<string>> &ans) {
        if (word == beginWord) {
            ans.push_back(path);
            return;
        }
        for (const string &p : parents[word]) {
            path.push_back(p);
            dfs(p, beginWord, parents, path, ans);
            path.pop_back();
        }
    }
};
