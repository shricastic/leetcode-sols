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
    int totalSum = 0;

    void dfs(TreeNode* root, int pathSum) {
        if (root == nullptr) {
            return;
        }
        pathSum = pathSum * 10 + root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            // Add the sum of the current path to the total sum
            totalSum += pathSum;
            return;
        }

        dfs(root->left, pathSum);
        dfs(root->right, pathSum);
    }

public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return totalSum;
    }
};
