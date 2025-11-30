class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for(int x : nums) total = (total + x) % p;

        if(total == 0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;

        long long prefix = 0;
        int n = nums.size();
        int ans = n;

        for(int i = 0; i < n; i++){
            prefix = (prefix + nums[i]) % p;

            // want: (prefix - previous) % p == total
            int want = (prefix - total + p) % p;

            if(mp.count(want))
                ans = min(ans, i - mp[want]);

            mp[prefix] = i;
        }

        return ans == n ? -1 : ans;
    }
};
