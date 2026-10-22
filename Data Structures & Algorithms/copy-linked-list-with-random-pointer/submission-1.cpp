/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head){
        unordered_map<Node*,Node*> mp;
        Node *temp = head,*prev = NULL;
        while(temp){
            mp[temp] = new Node(temp->val);
            if(prev) prev->next = mp[temp];
            prev = mp[temp];
            temp = temp->next;
        }
        temp = head;
        while(temp){
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
        // Node* temp = head;
        // while(temp){
        //     Node* node = new Node(temp->val);
        //     node->next = temp->next;
        //     temp->next = node;
        //     temp = temp->next->next;
        // }
        // temp = head;
        // while(temp){
        //     temp->next->random = (temp->random) ? temp->random->next : NULL;
        //     temp = temp->next->next;
        // }
        // temp = head;
        // Node dummy(0);
        // Node* curr = &dummy;
        // while(temp){
        //     curr->next = temp->next;
        //     temp->next = temp->next->next;
        //     curr = curr->next;
        //     temp = temp->next;
        // }
        // curr->next = NULL;
        // return dummy.next;
    }
};
