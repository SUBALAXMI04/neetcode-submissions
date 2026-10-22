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
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        int rem = 0;
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while(l1 || l2 || rem){
            if(l1){
                rem += l1->val;
                l1 = l1->next;
            }
            if(l2){
                rem += l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode(rem % 10);
            temp = temp->next;
            rem = rem/10;
        }
        return dummy.next;
    }
};
