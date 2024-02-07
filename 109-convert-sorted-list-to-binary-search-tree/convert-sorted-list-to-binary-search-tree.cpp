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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* maker(vector<int>& num,int si,int ei){
        if(si>=num.size()|| si>ei ||ei<0){
            return NULL;
        }
        int index=(si+ei)/2;
        TreeNode* root= new TreeNode(num[index]);
        root->left=maker(num,si,index-1);
        root->right=maker(num,index+1,ei);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        while(head!=NULL){
            nums.push_back(head->val);
            head=head->next;
        }
        return maker(nums,0,nums.size());
    }
};