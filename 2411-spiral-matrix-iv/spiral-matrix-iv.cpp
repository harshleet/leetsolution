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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int left=0,right=n-1,top=0,bottom=m-1;
        while(head !=NULL && top<=bottom && left<=right){
            for(int i=left;i<=right && head != NULL ;i++){
                ans[top][i]=head->val;
                head=head->next;
            }
            top++;
            for(int i=top;i<=bottom && head != NULL;i++){
                ans[i][right]=head->val;
                head=head->next;
            }
            right--;
            if(top<=bottom && head != NULL){
                    for(int i=right;i>=left && head != NULL;i--){
                        ans[bottom][i]=head->val;
                        head=head->next;
                    }
                    bottom--;
            }
               if(left<=right && head != NULL){
                    for(int i=bottom;i>=top && head != NULL ;i--){
                        ans[i][left]=head->val;
                        head=head->next;
                    }
                    left++;
               }

        }
        return ans;
    }
};