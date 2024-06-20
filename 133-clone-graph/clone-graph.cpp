/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* helper(Node* node,map<Node*,Node*>&vis){
        if(node==NULL){
            return NULL;
        }
        Node* r= new Node(node->val);
        vis[node]=r;
        
         cout<<r->val<<endl;
        for(auto it:node->neighbors){
            if(vis.find(it)==vis.end()){
                Node* temp=helper(it,vis);
                r->neighbors.push_back(temp);
            }else{
                 r->neighbors.push_back(vis[it]);
            }
        }
        return r;
    }
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>vis;
        return helper(node,vis);
    }
};