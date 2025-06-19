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
    int maxSum;
    int maxPath(TreeNode* root){
        if(root == nullptr) return 0;

        int lsum = maxPath(root->left);
        int rsum = maxPath(root->right);

        maxSum = max({maxSum, lsum + rsum + root->val, root->val + max(0, max(lsum, rsum))});
        return root->val + max(0, max(lsum, rsum));
    }
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxPath(root);
        return maxSum;
    }
};