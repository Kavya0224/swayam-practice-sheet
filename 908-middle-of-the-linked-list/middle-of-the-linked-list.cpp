/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Function to find the middle node of a singly linked list
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;  // Slow pointer moves one step at a time
        ListNode* fast = head;  // Fast pointer moves two steps at a time

        // Loop until fast reaches the end of the list
        // or there is no next node for fast to move forward
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move slow pointer one step
            fast = fast->next->next;    // Move fast pointer two steps
        }

        // When loop ends, slow pointer will be at the middle node
        return slow;
    }
};
