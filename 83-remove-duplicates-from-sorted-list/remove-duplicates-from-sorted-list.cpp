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
    ListNode* deleteDuplicates(ListNode* head) {
        // Keep a pointer to the head of the result list
        ListNode* res = head;

        // Traverse the list until the end
        while (head && head->next) {
            // If the current node and next node have the same value,
            // skip the next node (remove duplicate)
            if (head->val == head->next->val) {
                head->next = head->next->next;
            } else {
                // Otherwise, move to the next node
                head = head->next;
            }
        }

        // Return the head of the modified list (with duplicates removed)
        return res;        
    }
};
