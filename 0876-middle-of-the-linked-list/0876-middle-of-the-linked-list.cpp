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
        // cout << cnt;
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int l = length(head);
        int middle = l/2;
        // cout << middle;
        if(l==0){
            return NULL;
        }
        ListNode* temp = head;
        int i=1;
        while(i<=middle){
            i++;
            temp = temp->next;
        }
        return temp;
    }
};