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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>>pq;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                pq.push({-temp->val,temp});
                temp=temp->next;
            }
        }
        if(pq.empty()){
            return NULL;
        }
        ListNode* head=pq.top().second;
        ListNode* ans=head;
        pq.pop();
        while(!pq.empty()){
            ListNode* temp=pq.top().second;
            head->next=temp;
            head=temp;
            pq.pop();
        }
        head->next=NULL;
        return ans;
    }
};