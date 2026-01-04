class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            int cnt = 0;
            int sum = 0;

            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    int j = n / i;

                    cnt++;
                    sum += i;

                    if (i != j) {
                        cnt++;
                        sum += j;
                    }

                    if (cnt > 4) break;
                }
            }

            if (cnt == 4) ans += sum;
        }

        return ans;
    }
};
