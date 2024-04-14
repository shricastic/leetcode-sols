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
    int leftsum(TreeNode* root, bool isLeft) {
        if (root == nullptr) {
            return 0;
        }
        
        if (isLeft && root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        
        int left = leftsum(root->left, true);
        int right = leftsum(root->right, false);
        
        return left + right;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return leftsum(root, false);
    }
};
