/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        map<ListNode*,int>m; 
        while(head!=NULL){
              if(m.find(head)!=m.end()){
                  return true;
              }
              m[head]++;
              head=head->next;
        }
        return false;
    }
};