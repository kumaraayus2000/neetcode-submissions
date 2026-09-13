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

    ListNode * mergeTwoSortedLists(ListNode *l1,ListNode *l2){
        if(!l1){ 
            return l2;
        }
        if(!l2){
            return l1;
        }

        if(l1->val<=l2->val){
            l1->next= mergeTwoSortedLists(l1->next,l2);
        return l1;
        }else{
            l2->next=mergeTwoSortedLists(l1,l2->next);
            return l2;
        }
        return nullptr;
    }

    ListNode* partitionAndMerge(int s,int e, vector<ListNode*>& lists){
        if(s>e){
            return NULL;
        }
        if(s==e){
            return lists[s];
        }
        int mid = s +(e-s)/2;
        ListNode * l1 = partitionAndMerge(s,mid,lists);
        ListNode * l2 = partitionAndMerge(mid+1,e,lists);

        return mergeTwoSortedLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()-1 ==0){
            return nullptr;
        }
      return partitionAndMerge(0,lists.size()-1,lists);
        
    }
};
