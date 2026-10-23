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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            } else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = (l1) ? l1 : l2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        while(n > 1){
            for(int i = 0;i < n/2;i++) lists[i] = merge(lists[i],lists[n - 1 - i]);
            n = (n + 1)/2;
        }
        return lists[0];
    }
};
