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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp=head;
        ListNode* dummy=new ListNode(0);
        while(temp!=NULL){
            if(st.empty() || st.top()->val>temp->val){
                st.push(temp);
            }else{
                while(!st.empty() && st.top()->val<temp->val){
                    st.pop();
                }
                st.push(temp);
            }
            temp=temp->next;
        }
        if(st.empty()){
            return NULL;
        }
        vector<ListNode*>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        ListNode* temp2=dummy;
        for(int i=0;i<v.size();i++){
            temp2->next=v[i];
            temp2=temp2->next;
        }
        temp2->next=NULL;
        return dummy->next;
        

    }
};