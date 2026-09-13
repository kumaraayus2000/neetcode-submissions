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
        ListNode *tmp = head;
        while (tmp != NULL) {
            l++;
            tmp = tmp->next;
        }

        // Handle removing the head
        if (l == n) {
            ListNode *tmp2 = head;
            head = head->next;
            delete tmp2;
            return head; // ✅ Fix: return immediately after removing the head
        }

        int l1 = l - n - 1;
        ListNode *tmp3 = head;
        for (int i = 0; i < l1; i++) {
            tmp3 = tmp3->next;
        }
        ListNode *tmp4 = tmp3->next;
        tmp3->next = tmp3->next->next;
        delete tmp4;

        return head;
    }
};
