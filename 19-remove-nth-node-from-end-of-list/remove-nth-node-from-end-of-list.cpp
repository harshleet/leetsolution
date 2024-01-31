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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        
        int cnt=0;
        ListNode* prev=new ListNode(0);
        prev->next=head;
        temp=head;
        ListNode* pre=prev;
        while(temp!=NULL && cnt<size-n){
            pre=temp;
            temp=temp->next;
             
              cnt++;
        }
        pre->next=temp->next;
        return prev->next;
       
        
        

    }
};