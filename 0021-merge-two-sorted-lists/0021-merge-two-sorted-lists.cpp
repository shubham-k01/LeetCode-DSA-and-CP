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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* head3= new ListNode();
        ListNode* temp = head3;
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        if(head1->val <= head2->val){
            head3->val= head1->val;
            head1 = head1->next;
        }
        else{
            head3->val= head2->val;
            head2 = head2->next;
        }
        while(head1!=NULL && head2!=NULL){
            ListNode* node = new ListNode();
            if(head1->val <= head2->val){
                node->val= head1->val;
                head1 = head1->next;
            }
            else{
                node->val= head2->val;
                head2 = head2->next;
            }
            head3->next = node;
            head3 = head3->next;
        }
        while(head1!=NULL){
            ListNode* node = new ListNode();
            node->val= head1->val;
            head1 = head1->next;
            head3->next = node;
            head3 = head3->next;
        }
        while(head2!=NULL){
            ListNode* node = new ListNode();
            node->val= head2->val;
            head2 = head2->next;
            head3->next = node;
            head3 = head3->next;
        }
        return temp;
    }
};