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
private:
    vector<string> res;

    void findPaths(TreeNode* root, string s){
        if(root->left == nullptr && root->right == nullptr){ 
            res.push_back(s);
            return;
        }

        if(root->left) findPaths(root->left, s + "->" + to_string(root->left->val));
        if(root->right) findPaths(root->right, s + "->" + to_string(root->right->val));
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res; 
        findPaths(root, to_string(root->val));
        return res;
    }
};
