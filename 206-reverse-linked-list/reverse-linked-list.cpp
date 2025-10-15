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
    // Function to reverse a singly linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;    // Previous node pointer, initially NULL
        ListNode* curr = head;    // Current node pointer, starts at head
        ListNode* next = NULL;    // Next node pointer to keep track of next node

        // Iterate through the list until current node is NULL (end of list)
        while (curr != NULL) {
            next = curr->next;    // Save next node before changing current's next
            curr->next = prev;    // Reverse current node's pointer to point to previous node
            prev = curr;          // Move prev to current node
            curr = next;          // Move curr to next node (saved earlier)
        }

        // After loop, prev points to new head of the reversed list
        return prev;
    }
};
