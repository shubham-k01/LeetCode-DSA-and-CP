/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(slow!=NULL && fast!=NULL){
            slow = slow->next;
            if(fast->next){
                fast = fast->next;
            }
            fast = fast->next;
            if(slow==fast){
                return slow;
            }
        }
        return NULL;
        
    }
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL){
            return NULL;
        }
        ListNode* intr = hasCycle(head);
        if(intr==NULL){
            return NULL;
        }
        ListNode* n = head;
        while(n!=intr){
            n = n->next;
            intr = intr->next;
        }
        return n;
    }
};