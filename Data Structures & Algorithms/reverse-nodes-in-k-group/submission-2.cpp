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
    ListNode* reverseKGroup(ListNode* head, int k) {

       // Base cases:
        // 1) If list is empty, just return
        // 2) If k == 1, reversing groups of size 1 does nothing
        if (!head || k == 1) return head;
        // --- Step 1: Check if there are at least k nodes ahead ---
        // We only reverse when we have k nodes, otherwise leave the list unchanged
        ListNode* check = head;
        for (int i = 0; i < k; ++i) {
            if (!check) return head;  // Not enough nodes -> return as is
            check = check->next;
        }
        // --- Step 2: Reverse exactly k nodes ---
        // Classic linked list reversal pattern
        ListNode* prev = nullptr;     // will become new head of this block
        ListNode* curr = head;        // start from current head
        for (int i = 0; i < k; ++i) {
            ListNode* next = curr->next; // store next node
            curr->next = prev;           // reverse pointer
            prev = curr;                 // move prev forward
            curr = next;                 // move curr forward
        }
        // Now 'prev' points to new head of reversed block
        // and 'curr' points to first node of the next block

        // --- Step 3: Recurse for the remaining list ---
        // head (old head) is now the tail of the reversed block,
        // so we connect it to the result of reversing the next groups
        head->next = reverseKGroup(curr, k);

        // Return new head of this block (prev)
        return prev;
    }
};
