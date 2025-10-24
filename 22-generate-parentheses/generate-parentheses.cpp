class Solution {
public:
    // Main function to generate all valid combinations of parentheses
    vector<string> generateParenthesis(int n) {
        vector<string> res; // To store all valid parentheses combinations
        
        // Start the recursive depth-first search (DFS)
        dfs(0, 0, "", n, res);
        
        return res;        
    }

private:
    // Recursive DFS helper function
    // openP  -> number of '(' used so far
    // closeP -> number of ')' used so far
    // s      -> current parentheses string being built
    // n      -> total pairs of parentheses
    // res    -> stores all valid combinations
    void dfs(int openP, int closeP, string s, int n, vector<string>& res) {
        
        // Base case: if we've used all parentheses and it's balanced
        if (openP == closeP && openP + closeP == n * 2) {
            res.push_back(s); // Add the valid combination
            return;
        }

        // If we still have remaining '(' to use, add one and recurse
        if (openP < n) {
            dfs(openP + 1, closeP, s + "(", n, res);
        }

        // If we have more '(' than ')' used so far, we can safely add a ')'
        if (closeP < openP) {
            dfs(openP, closeP + 1, s + ")", n, res);
        }
    }
};
