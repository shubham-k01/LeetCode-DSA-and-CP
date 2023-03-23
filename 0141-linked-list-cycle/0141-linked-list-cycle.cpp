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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return false;
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
                return true;
            }
        }
        return false;
        
    }
};