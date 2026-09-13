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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* tmp = head;
        while (tmp != NULL) {
            l++;
            tmp = tmp->next;
        }

        // If we need to remove the head
        if (n == l) {
            ListNode* newHead = head->next;
            delete head; // free memory if needed
            return newHead;
        }

        ListNode* curr = head;
        for (int i = 0; i < l - n - 1; i++) {
            curr = curr->next;
        }

        ListNode* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete; // free memory if needed

        return head;
    }
};
