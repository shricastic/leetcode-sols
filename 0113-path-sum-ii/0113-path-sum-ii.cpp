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
    vector<vector<int>> paths;
    void dfs(TreeNode* root, int target, vector<int> cur){
        if (!root) return;

        cur.push_back(root->val);
        
        if (!root->left && !root->right && target == root->val) {
            paths.push_back(cur);
            return;
        }

        dfs(root->left, target-root->val, cur);
        dfs(root->right, target-root->val, cur);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target, {});
        return paths;
    }
};