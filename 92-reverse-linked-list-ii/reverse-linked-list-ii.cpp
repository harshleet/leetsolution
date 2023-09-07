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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         if (!head || left == right) {
            return head;
        }
       
        ListNode* cur=head;
        ListNode * dummy=new ListNode(-1);
        ListNode* back=dummy;
        dummy->next=head;
        for(int i=1;i<left;i++){
            back=cur;
            cur=cur->next;
        }
        
   
       ListNode* subHead=cur;
       ListNode* prev=NULL;
        for (int i = 0; i <=right - left; i++) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        back->next=prev;
        subHead->next=cur;
       
    
        return dummy->next;
    }
};