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
    void reorderList(ListNode* head) {
       if(!head || !head->next){
        return; 
       } 
        ListNode *slow=head;
        ListNode *fast=head;
        //find middle
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        //reverse second list
        ListNode *prev=NULL;
        ListNode *curr= slow->next;
        ListNode *tmp = curr;
        while(curr!=NULL){
            tmp=tmp->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }
        slow->next=NULL;

        //first and second lists 
        ListNode *first = head;
        ListNode *second = prev;


        while(second!=NULL){
            ListNode *tmp1=first->next;
            ListNode *tmp2=second->next;

            first->next=second;
            second->next=tmp1;
            first=tmp1;
            second=tmp2;
        }

    }
};
