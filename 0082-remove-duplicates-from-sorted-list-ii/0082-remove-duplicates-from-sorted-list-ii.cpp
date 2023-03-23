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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        map<int,int> mp;
        while(temp!=NULL){
            mp[temp->val]++;
            temp = temp->next;
        }
        
        temp = head;
        while(temp!=NULL){
            if(mp[temp->val]>1){
                int cnt = mp[temp->val];
                while(cnt>0){
                    if(prev==NULL){
                        // prev = temp;
                        temp = temp->next;
                        // delete prev;
                        // prev = NULL;
                        head = temp;
                    }
                    else{
                        prev->next = temp->next;
                        // delete temp;
                        temp = prev->next;
                    }
                    cnt--;
                }
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};