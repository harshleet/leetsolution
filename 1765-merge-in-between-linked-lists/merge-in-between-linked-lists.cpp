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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head1=list1;
        ListNode* head2=list1;
        ListNode* temp=list1;
       int c=1;
       while(list1!=NULL){
           
           if(c==a){
               head1=list1;
           }
           if(c==b+1){
               head2=list1;
           }
           c++;
           list1=list1->next;
       }
        head1->next=list2;
        while(list2->next!=NULL){
            list2=list2->next;
        }
        list2->next = head2->next;
       
        return temp;
    }
};