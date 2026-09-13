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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
         // Create a dummy node to simplify list construction
        // (avoids special case for the first node)
        ListNode* dummy = new ListNode(0);

        // 'curr' will always point to the last node in the result list
        ListNode* curr = dummy;

        // carry stores overflow when sum >= 10
        int carry = 0;

        // Process until both lists are empty AND no carry left
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            // Get current values (0 if list is already finished)
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            // Compute sum and update carry
            int sum = x + y + carry;
            carry = sum / 10;   // carry for next digit

            // Create new node for the current digit (sum % 10)
            curr->next = new ListNode(sum % 10);

            // Move curr pointer forward
            curr = curr->next;

            // Move l1 and l2 pointers forward if available
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // Final result starts at dummy->next (skip the dummy node)
        return dummy->next;
    }
};
