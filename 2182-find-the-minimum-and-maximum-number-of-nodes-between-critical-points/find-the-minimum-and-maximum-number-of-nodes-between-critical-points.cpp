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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return {-1,-1};
        }
        vector<int>st;
        ListNode* temp=head;
        ListNode* nxt=head->next;
        ListNode* prev=NULL;
         int mini=-1,maxi=-1,first=-1,pre=-1;
         int i=0;
        while(temp!=NULL && nxt!=NULL){
            if(prev!=NULL){
                if((temp->val>prev->val && temp->val>nxt->val) || (temp->val<prev->val && temp->val<nxt->val)){
                    if(first==-1){
                        first=i;
                    }
                    if(pre!=-1){
                        if(mini==-1){
                            mini=i-pre;
                        }else{
                            mini=min(mini,i-pre);
                        }
                    
                    }
                    pre=i;
                }
            }
            i++;
            prev=temp;
            temp=temp->next;
            nxt=nxt->next;
        }
       
      
        if(first!=-1 && pre!=-1 && pre!=first){
            maxi=max(maxi,pre-first);
        }
        return {mini,maxi};
    }
};