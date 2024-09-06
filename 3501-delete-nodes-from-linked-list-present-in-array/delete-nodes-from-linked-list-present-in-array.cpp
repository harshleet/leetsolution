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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st(nums.begin(),nums.end());
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(head!=NULL){
            if(st.find(head->val)==st.end()){
                dummy->next=head;
                dummy=head;
            }
            head=head->next;
        }
        dummy->next=NULL;
        return temp->next;
    }
};