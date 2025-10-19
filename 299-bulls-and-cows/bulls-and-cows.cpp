class Solution {
public:
    string getHint(string s, string g)  // s = secret, g = guess
    {
        vector<int> map(10);  // To count frequency of each digit (0-9) in secret string

        int n = s.size();
        int cntb = 0;  // To count bulls (correct digit & correct position)

        // First pass: Count all digits in secret and identify bulls
        for(int i = 0 ; i < n ; i++)
        {
            map[s[i] - '0']++;  // Count occurrence of digit in secret
        }

        // Second pass: Identify bulls and reduce their count in map
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == g[i])  // If characters match at the same index (bull)
            {
                cntb++;  // Increment bull count
                map[s[i] - '0']--;  // Reduce count of that digit since it's already matched
            }
        }

        int cnt2 = 0;  // To count cows (correct digit, wrong position)

        // Third pass: Identify cows (correct digit, wrong position)
        for(int i = 0 ; i < n ; i++)
        {
            if(g[i] == s[i]) continue;  // Skip bulls

            // If the guessed digit exists in the map and wasn't used up by bulls or earlier cows
            if(map[g[i] - '0'] > 0)
            {
                cnt2++;  // Count as cow
                map[g[i] - '0']--;  // Mark this digit as used
            }
        }

        // Construct final result string: "<bulls>A<cows>B"
        string ans = to_string(cntb) + 'A' + to_string(cnt2) + 'B';
        return ans;
    }
};
