class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Maps to store the first occurrence index of each character in s and t
        unordered_map<char, int> charIndexS;
        unordered_map<char, int> charIndexT;

        // Iterate through both strings simultaneously
        for (int i = 0; i < s.length(); i++) {
            // If character from s is seen for the first time, map it to the current index
            if (charIndexS.find(s[i]) == charIndexS.end()) {
                charIndexS[s[i]] = i;
            }

            // If character from t is seen for the first time, map it to the current index
            if (charIndexT.find(t[i]) == charIndexT.end()) {
                charIndexT[t[i]] = i;
            }

            // Compare the first occurrence indices of s[i] and t[i]
            // If they differ, then the mapping isn't consistent → not isomorphic
            if (charIndexS[s[i]] != charIndexT[t[i]]) {
                return false;
            }
        }

        // If all characters matched consistently, strings are isomorphic
        return true; 
    }
};
