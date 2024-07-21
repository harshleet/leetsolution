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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=new ListNode(0);
        ListNode* newh=temp;
        ListNode* t=head;
         while(t!=NULL){
            stack<ListNode*>st;
            int i=0;
            ListNode* t2=t;
            while(t!=NULL && i<k){
                st.push(t);
                 t=t->next;
                 i++;
            }
            if(i%k==0){
               while(!st.empty()){
                    temp->next=st.top();
                    st.pop();
                    temp=temp->next;
                } 
            }else{
                while(t2!=NULL){
                    temp->next=t2;
                    temp=temp->next;
                    t2=t2->next;
                }
            }
         }
         temp->next=NULL;
         return newh->next;
    }
};