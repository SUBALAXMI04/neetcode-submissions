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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *curr = head,*prev = NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head){
        if(!head || !head->next) return;
        ListNode *slow = head,*fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode dummy(0);
        ListNode *secHead = reverse(slow->next),*fHead = head,*temp = &dummy;
        slow->next = NULL;
        while(secHead && fHead){
            temp->next = fHead;
            fHead = fHead->next;
            temp = temp->next;

            temp->next = secHead;
            secHead = secHead->next;
            temp = temp->next;
        }
        if(fHead) temp->next = fHead;
        head = dummy.next;
    }
};
