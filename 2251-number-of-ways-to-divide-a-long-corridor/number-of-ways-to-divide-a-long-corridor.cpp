class Solution {
public:
    int numberOfWays(string s) {
        const int MOD = 1e9 + 7;

        int seats = 0;
        for (char c : s) {
            if (c == 'S') seats++;
        }

        if (seats == 0 || seats % 2 != 0) return 0;
        if (seats == 2) return 1;

        long long ans = 1;
        int seatCount = 0;
        int plants = 0;

        for (char c : s) {
            if (c == 'S') {
                seatCount++;
                if (seatCount > 2 && seatCount % 2 == 1) {
                    ans = (ans * (plants + 1)) % MOD;
                    plants = 0;
                }
            } else if (seatCount >= 2 && seatCount % 2 == 0) {
                plants++;
            }
        }

        return ans;
    }
};
