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
Node* clone(Node* node, unordered_map<Node*, Node*>& visited) {
    if (!node) return nullptr;

    if (visited.count(node)) return visited[node];

    Node* cloneNode = new Node(node->val);
    visited[node] = cloneNode; 

    for (Node* neighbor : node->neighbors) {
        cloneNode->neighbors.push_back(clone(neighbor, visited));
    }

    return cloneNode;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> visited;
    return clone(node, visited);
}
};