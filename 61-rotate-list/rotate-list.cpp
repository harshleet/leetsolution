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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
         //i m taking extra space
         int size=0;
         ListNode* last=head;
         while(last->next!=NULL){
             size++;
             last=last->next;
         }
         if(k%(size+1)==0){
             return head;
         }
         int moves=size+1-k%(size+1);
         int i=0;
         ListNode* temp=NULL;
         ListNode* t3=head;
         while(t3!=NULL && i<moves ){
            temp=t3;
            t3=t3->next;
            i++;
         }
         ListNode* t2=temp->next;
         temp->next=NULL;
         last->next=head;
         return t2;
         
    }
};