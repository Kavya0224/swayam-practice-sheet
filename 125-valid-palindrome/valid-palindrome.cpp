class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";

        // Step 1: Clean the input string
        // Loop through each character in the input string
        for (char c : s) {
            // If the character is alphanumeric (letter or digit)
            if (isalnum(c)) {
                // Convert it to lowercase and add it to the cleaned string
                cleaned += tolower(c);
            }
        }

        // Step 2: Reverse the cleaned string
        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());

        // Step 3: Compare the cleaned string with its reverse
        // If they are the same, it's a palindrome
        return cleaned == reversed;
    }
};
