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
        vector<int>st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push_back(temp->val);
            temp=temp->next;
        }
        int mini=-1,maxi=-1,first=-1,pre=-1;
        for(int i=1;i<st.size()-1;i++){
            if((st[i]>st[i-1]&& st[i]>st[i+1]) || (st[i+1]>st[i] && st[i-1]>st[i])){
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
        if(first!=-1 && pre!=-1 && pre!=first){
            maxi=max(maxi,pre-first);
        }
        return {mini,maxi};
    }
};