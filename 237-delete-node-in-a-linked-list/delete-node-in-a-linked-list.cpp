/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Pointer to the node that will be removed (the next node)
ListNode* toDelete = node->next;

// Copy the value from the next node into the current node
node->val = toDelete->val;

// Bypass the next node by updating the current node's next pointer
node->next = toDelete->next;

// Delete the removed node to free memory and avoid leaks
delete toDelete;

    }
};