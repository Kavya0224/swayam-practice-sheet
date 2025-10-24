class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_dollars = 0;  // Count of $5 bills
        int ten_dollars = 0;   // Count of $10 bills
        
        // Iterate over each customer's bill
        for (int x : bills) {
            
            // Case 1: Customer pays with a $5 bill
            // No change needed; just add it to our count
            if (x == 5) {
                five_dollars++;
            } 
            
            // Case 2: Customer pays with a $10 bill
            // Need to give back $5 as change
            else if (x == 10) {
                if (five_dollars > 0) {
                    five_dollars--;   // Give one $5 as change
                    ten_dollars++;    // Keep the $10 bill
                } else {
                    return false;     // Cannot give change
                }
            } 
            
            // Case 3: Customer pays with a $20 bill
            // Need to give back $15 as change
            else {
                // Prefer giving one $10 + one $5 (greedy approach)
                if (five_dollars > 0 && ten_dollars > 0) {
                    five_dollars--;
                    ten_dollars--;
                } 
                // Otherwise, try giving three $5 bills
                else if (five_dollars >= 3) {
                    five_dollars -= 3;
                } 
                // If neither option works, we cannot make change
                else {
                    return false;
                }
            }
        }
        
        // If we successfully gave change to every customer
        return true;
    }
};
