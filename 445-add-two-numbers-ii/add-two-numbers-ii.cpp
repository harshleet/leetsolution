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
    ListNode* l3 =NULL;
    ListNode* reverse(ListNode* head)
    {
        // Initialize current, previous and next pointers
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
           
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
   int count(ListNode* head){
         ListNode* current = head;
       int coun=0;
 
        while (current != NULL) {
            coun++;
            current = current->next;
        }  
        return coun;
    }
 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *head1=  reverse(l1);
      ListNode *head2 = reverse(l2);
      ListNode *t1=head1;
     ListNode *t2=head2;
   
    ListNode *head=new ListNode();
    ListNode *temp=head;

     int carry=0;
        while( t1!=NULL || t2!=NULL ||carry){
            int sum=0;
           
            if(t1!=NULL){
                sum+=t1->val;
                t1=t1->next;
          }
        if(t2!=NULL){
                sum+=t2->val;
                t2=t2->next;
          }
           sum+=carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            temp->next=node;
            temp=node;
        }
         ListNode *t3=  reverse(head->next);
       return t3;
    }
};