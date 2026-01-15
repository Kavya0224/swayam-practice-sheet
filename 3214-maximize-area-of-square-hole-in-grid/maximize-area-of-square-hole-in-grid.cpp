class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int ct = 1, mx = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1)
                ct++;
            else
                ct = 1;
            mx = max(mx, ct);
        }

        int ct1 = 1, mx1 = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1)
                ct1++;
            else
                ct1 = 1;
            mx1 = max(mx1, ct1);
        }

        int side = min(mx + 1, mx1 + 1);
        return side * side;
    }
};
