//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    
    struct Node* reverse(struct Node* head){
        struct Node* prev = NULL;
        struct Node* curr = head;
        struct Node* next = head->next;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        return head;
    }
    
    void insertAtTail(struct Node* &head, int v){
        struct Node* node = new Node(v);
        if(head==NULL){
            head = node;
            return;
        }
        struct Node* temp = head ;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = node;
        return;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        struct Node* final = NULL;
        
        int carry = 0,sum,val1,val2;
        
        while(carry!= 0 || first!=NULL || second!=NULL){
            val1 = 0;
            if(first!=NULL){
                val1 = first->data;
            }
            val2 = 0;
            if(second!=NULL){
                val2 = second->data;
            }
            
            sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            insertAtTail(final,sum);
            
            if(first!=NULL)
                first = first->next;
            
            if(second!=NULL)
                second = second->next;
        }
        
        return reverse(final);
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends