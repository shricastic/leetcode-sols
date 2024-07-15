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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map;
        unordered_set<int> childs;
        
        for(auto desc : descriptions){
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];
            
            if(map.find(parent) == map.end()){
                map[parent] = new TreeNode(parent);                
            }
            
            if(map.find(child) == map.end()){
                map[child] = new TreeNode(child);
            }
            
            if(isLeft) map[parent]->left = map[child];
            else map[parent]->right = map[child];
            
            childs.insert(child);
        }     
        
        TreeNode* root = nullptr;
        
        for(auto node : map){
            if(childs.find(node.first) == childs.end()){
                root = node.second;
                break;
            }
        }
        
        return root;
    }
};