class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long sum = 0;
        int ct = 0;
        int n = happiness.size();

        for (int i = n - 1; i >= 0 && ct < k; i--) {
            int temp = happiness[i] - ct;
            if (temp < 0) temp = 0;
            sum += temp;
            ct++;
        }
        return sum;
    }
};
