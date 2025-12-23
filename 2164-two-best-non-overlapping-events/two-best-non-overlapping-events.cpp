class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        // Sort by start time
        sort(events.begin(), events.end());
        
        // Store {endTime, value}
        vector<pair<int,int>> ends;
        for (auto &e : events) {
            ends.push_back({e[1], e[2]});
        }
        
        // Sort by end time
        sort(ends.begin(), ends.end());
        
        // Prefix max of values
        vector<int> prefMax(n);
        prefMax[0] = ends[0].second;
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i-1], ends[i].second);
        }
        
        int ans = 0;
        
        for (auto &e : events) {
            int start = e[0];
            int value = e[2];
            
            // Binary search last event ending < start
            int l = 0, r = n - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (ends[mid].first < start) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            if (idx != -1) {
                ans = max(ans, value + prefMax[idx]);
            }
            
            // Case: single event
            ans = max(ans, value);
        }
        
        return ans;
    }
};
