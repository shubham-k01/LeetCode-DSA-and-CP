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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
            
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        int cnt = 1;
        while(cnt<k){
            curr = curr->next;
            if(curr==NULL){
                return head;
            }
            cnt++;
        }
        cnt = 0;
        curr = head;
        while(cnt<k && curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        
        if(forward){
            head->next = reverseKGroup(forward,k);
        }
        
        return prev;
        
        
    }
};