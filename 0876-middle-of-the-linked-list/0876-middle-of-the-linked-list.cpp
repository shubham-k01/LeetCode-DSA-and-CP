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
    int length(ListNode* head){
        if(head==NULL){
            return 0;
        }
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
//     ListNode* middleNode(ListNode* head) {
//         if(head==NULL){
//             return head;
//         }
//         int l = length(head);
//         int middle = l/2;
        
//         ListNode* temp = head;
//         int i=1;
//         while(i<=middle){
//             i++;
//             temp = temp->next;
//         }
//         return temp;
//     }
    
    ListNode* middleNode(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        if(head->next->next==NULL){
            return head->next;
        }
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast!=NULL){
            if(fast->next){
                fast = fast->next;
            }
            fast = fast->next;
            slow=slow->next;
        }
        
        return slow;
    }
};