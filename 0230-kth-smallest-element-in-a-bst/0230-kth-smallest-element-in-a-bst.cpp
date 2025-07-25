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
    vector<int> res;
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        if(res.size()<k) return -1;

        return res[k-1];
    }
};