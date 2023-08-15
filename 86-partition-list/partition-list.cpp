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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL){
            return NULL;
        }
       ListNode* ss=NULL;
       ListNode* se=NULL;
       ListNode* ls=NULL;
       ListNode* le=NULL;
       ListNode* cur=head;
       while(cur!=NULL){
           if(cur->val<x){
                if(ss==NULL && se==NULL){
                    ss=cur;
                    se=cur;
                }else{
                    se->next=cur;
                    se=se->next;
                }
           }else{
               if(ls==NULL && le==NULL){
                    ls=cur;
                    le=cur;
                }else{
                    le->next=cur;
                    le=le->next;
                }
           }
           cur=cur->next;
       }
               if(ls==NULL || se==NULL  ){
            return head;
        }

       le->next=NULL;
       se->next=ls;
       return ss;
    }
};