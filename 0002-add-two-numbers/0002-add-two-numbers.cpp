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
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next; 
        }
        
        return prev;
    }
    
    void insertTail(ListNode* &head,int v){
        ListNode* temp = new ListNode(v);
        if(head==NULL){
            head = temp;
            return;
        }
        ListNode* t = head;
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = temp;
        return;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = (l1);
        ListNode* second = (l2);
        ListNode* ans;
        
        int carry = 0,sum,val1,val2;
        
        while(carry!= 0 || first!=NULL || second!=NULL){
            val1 = 0;
            if(first!=NULL){
                val1 = first->val;
            }
            val2 = 0;
            if(second!=NULL){
                val2 = second->val;
            }
            
            sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            insertTail(ans,sum);
            
            if(first!=NULL)
                first = first->next;
            
            if(second!=NULL)
                second = second->next;
        }
        
        return ans;
    }
};