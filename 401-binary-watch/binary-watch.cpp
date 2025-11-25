class Solution {
public:
    vector<string> readBinaryWatch(int t) {
        vector<vector<int>> H(5), M(7);
        for (int i = 0; i < 12; i++) H[__builtin_popcount(i)].push_back(i);
        for (int i = 0; i < 60; i++) M[__builtin_popcount(i)].push_back(i);
        
        vector<string> ans;
        for (int i = 0; i <= t; i++) {
            if (i < H.size() && t - i < M.size()) {
                for (int h : H[i]) {
                    for (int m : M[t - i]) {
                        ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                    }
                }
            }
        }
        return ans;
    }
};
