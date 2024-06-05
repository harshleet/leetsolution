/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> in;
    int i = 0;
    void construct(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        construct(root->left);
        in.push_back(root->val);
        construct(root->right);
    }
    BSTIterator(TreeNode* root) { construct(root); }

    int next() {
        return in[i++];
    }

    bool hasNext() {
        if(i<in.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */