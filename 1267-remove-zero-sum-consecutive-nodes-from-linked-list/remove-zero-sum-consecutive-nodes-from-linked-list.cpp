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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        map<int,ListNode*>m;
        m[0]=dummy;
        ListNode* temp=head;
        ListNode* temp2=head;
        int sum=0;
        while(temp!=NULL){
           sum+=temp->val;
           if(m.find(sum)!=m.end()){
            int tsum=sum;
            ListNode* pre=m[sum];
            ListNode* last=pre;
            while(pre!=temp){
                pre=pre->next;
                tsum+=pre->val;
                 if(pre!=temp)m.erase(tsum);
            }
            last->next=temp->next;
           }else{
             m[sum]=temp;
           }
          
           temp=temp->next;
        }
        return dummy->next;
    }



};