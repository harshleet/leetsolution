/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void helper(Node* root,int lvl,map<int,vector<int>>&m){
        if(root==NULL){
            return ;
        }
        m[lvl].push_back(root->val);
        for(auto it: root->children){
            helper(it,lvl+1,m);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        map<int,vector<int>>v;
        helper(root,0,v);
        vector<vector<int>> ans;
        for (const auto& pair : v) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};