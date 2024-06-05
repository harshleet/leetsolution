/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        // lvl order traversal
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        ans += to_string(root->val);
        ans += ",";
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(node->left);
                    ans += to_string(node->left->val);
                    ans += ",";
                } else {
                    ans += "#";
                    ans += ",";
                }
                if (node->right != NULL) {
                    q.push(node->right);
                    ans += to_string(node->right->val);
                    ans += ",";
                } else {
                    ans += "#";
                    ans += ",";
                }
            }
        }
        cout << ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        stringstream ss(data);
        string number;
        getline(ss, number, ',');
        TreeNode* root = new TreeNode(stoi(number));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (getline(ss, number, ',')) {
                    if (number == "#") {
                        node->left = NULL;
                    } else {
                        TreeNode* temp = new TreeNode(stoi(number));
                        node->left = temp;
                        q.push(temp);
                    }
                }
                if (getline(ss, number, ',')) {
                    if (number == "#") {
                        node->right = NULL;
                    } else {
                        TreeNode* temp = new TreeNode(stoi(number));
                        node->right = temp;
                        q.push(temp);
                    }
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));