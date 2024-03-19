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
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            ListNode* ref=lists[i];
            while(ref!=NULL){
                  pq.push({ref->val,ref});
                  ref=ref->next;
            }

        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(!pq.empty()){
            temp->next=pq.top().second;
           cout<<pq.top().first;
            temp=temp->next;
             pq.pop();
        }
        temp->next=NULL;
        return dummy->next;
    }
};