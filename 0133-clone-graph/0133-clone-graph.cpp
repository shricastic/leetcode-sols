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
private:
    unordered_map<Node*, Node*> map;
    Node* dfs(Node* root){
        if(root == nullptr) return nullptr;
        if(map.count(root) != 0) return map[root];

        Node* newNode = new Node(root->val);
        map[root] = newNode;

        for(auto n : root->neighbors){
            newNode->neighbors.push_back(dfs(n));
        }

        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};