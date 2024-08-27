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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st;
        int i = 0;
        int n = traversal.size();

        string dig = "";
        while (i < n && traversal[i] != '-') {
            dig += traversal[i];
            i++;
        }
        TreeNode* root = new TreeNode(stoi(dig));
        st.push({root, 0});

        while (i < n) {
            int cnt = 0;

            while (i < n && traversal[i] == '-') {
                cnt++;
                i++;
            }

            dig = "";
            while (i < n && traversal[i] != '-') {
                dig += traversal[i];
                i++;
            }
            int val = stoi(dig);

            TreeNode* node = new TreeNode(val);

            while (!st.empty() && st.top().second >= cnt) {
                st.pop();
            }

            if (st.top().first->left == nullptr) {
                st.top().first->left = node;
            } else {
                st.top().first->right = node;
            }

            st.push({node, cnt});
        }

        return root;
    }
};
