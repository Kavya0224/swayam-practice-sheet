class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> level;
        level.insert(s);

        while (true) {
            vector<string> valid;

            // Collect all valid strings at current level
            for (const string &str : level) {
                if (isValid(str)) {
                    valid.push_back(str);
                }
            }

            // If any valid strings found at current level, return them
            if (!valid.empty()) return valid;

            // Otherwise, generate next level by removing one parenthesis from each string
            unordered_set<string> nextLevel;
            for (const string &str : level) {
                for (int i = 0; i < str.size(); i++) {
                    if (str[i] != '(' && str[i] != ')') continue;
                    string t = str.substr(0, i) + str.substr(i + 1);
                    nextLevel.insert(t);
                }
            }

            level = move(nextLevel);
        }
    }

    // Check if string has valid parentheses
    bool isValid(const string &s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }
};
