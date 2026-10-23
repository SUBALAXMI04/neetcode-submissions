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
    ListNode* KNode(ListNode* head,int k){
        for(int i = 1;i < k;i++){
            if(head) head = head->next;
            else return NULL;
        } 
        return head;
    }
    ListNode* reverseKGroup(ListNode* head,int k){
        ListNode *temp = head,*grpPrev = NULL,*grpNext = NULL;
        while(temp){
            ListNode* kthNode = KNode(temp,k);
            if(!kthNode) break;
            grpNext = kthNode->next;
            kthNode->next = NULL;
            ListNode *curr = temp,*prev = NULL;
            while(curr){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(temp == head) head = kthNode;
            if(grpPrev) grpPrev->next = kthNode;
            grpPrev = temp;
            temp = grpNext;
        }
        if(grpPrev) grpPrev->next = temp;
        return head;
    }
};
