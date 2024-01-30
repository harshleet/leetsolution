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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
           temp=temp->next;
        }
        int each_size=size/k;
        int ext=size%k;
        cout<<ext<<endl;
        vector<int>si(k,each_size);
        for(int i=0;i<ext;i++){
            si[i]++;
        }
        int ind=0;
        vector<ListNode*>ans(k,NULL);
        
        while(head!=NULL && ind<k){
            int cnt=si[ind];
            cout<<cnt<<" ";
            if(head!=NULL){
                ans[ind]=head;
            }
            ListNode* t=head;
            while(t!=NULL && cnt>1){
                t=t->next;
                cnt--;
            }
            if(t!=NULL){
            head=t->next;
            t->next=NULL;
            }
            ind++;
        }
        return ans;
    }
};