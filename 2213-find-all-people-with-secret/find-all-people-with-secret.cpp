class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b) {
            parent[find(a)] = find(b);
        };

        vector<int> know(n, 0);
        know[0] = 1;
        know[firstPerson] = 1;

        for(int i = 0; i < meetings.size(); ) {
            int time = meetings[i][2];
            vector<pair<int,int>> batch;

            int j = i;
            while(j < meetings.size() && meetings[j][2] == time) {
                unite(meetings[j][0], meetings[j][1]);
                batch.push_back({meetings[j][0], meetings[j][1]});
                j++;
            }

            unordered_set<int> informed;
            for(auto &p : batch) {
                if(know[p.first] || know[p.second]) {
                    informed.insert(find(p.first));
                    informed.insert(find(p.second));
                }
            }

            for(auto &p : batch) {
                if(informed.count(find(p.first)) ||
                   informed.count(find(p.second))) {
                    know[p.first] = know[p.second] = 1;
                } else {
                    parent[p.first] = p.first;
                    parent[p.second] = p.second;
                }
            }

            i = j;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(know[i]) ans.push_back(i);

        return ans;
    }
};
