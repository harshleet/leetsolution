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
        int size=0;
        ListNode* temp=head;
        while(temp->next!=NULL){
            size++;
            temp=temp->next;
        }
        if(k%(size+1)==0){
            return head;
        }
        int actual=k%(size+1);
        ListNode* temp2=head;
        ListNode* start=NULL;
        int cov=0;
        while(temp2!=NULL && cov<(size)-actual){
            temp2=temp2->next;
            cov++;
        }
        start=temp2->next;
        temp2->next=NULL;
        temp->next=head;
        return start;
   
    }
};