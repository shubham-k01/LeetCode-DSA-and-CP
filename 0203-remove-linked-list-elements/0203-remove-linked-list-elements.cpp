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
    // ListNode* removeElements(ListNode* head, int val) {
    //     if(head==NULL){
    //         return NULL;
    //     }
    //     if(head->val==val){
    //         return removeElements(head->next,val);
    //     }
    //     head->next = removeElements(head->next,val);
    //     return head;
    // }
    
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            if(curr->val==val){
                if(prev==NULL){
                    prev = curr;
                    curr = curr->next;
                    delete prev;
                    prev=NULL;
                    head = curr;
                }
                else{
                    prev->next=curr->next;
                    delete curr;
                    curr = prev->next;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
    
    
};