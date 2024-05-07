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
#include <iostream>
#include <string>
class Solution {
public:
    int helper(ListNode* head){
        if(head==NULL){
            return -1;
        }
        int valu=2*(head->val);
        int carry=helper(head->next);
        if(carry!=-1){
        valu+=carry;}
        head->val=valu%10;
        return valu/10;
        
    }
    ListNode* doubleIt(ListNode* head) {
      
        ListNode* temp=head;
         int first=helper(temp);
        if(first==0  || first==-1){
            return head;
        }
        ListNode* st=new ListNode(first);
        st->next=head;
        return st;
    
    }
};