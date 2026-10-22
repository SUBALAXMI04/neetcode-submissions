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
    int size(ListNode* head){
        int len = 1;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head,int n){
        int len = size(head);
        if(n == len) return head->next;
        n = n % len;
        ListNode dummy(0,head);
        ListNode *slow = &dummy,*fast = &dummy;
        for(int i = 1;i <= n;i++) fast = fast->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
