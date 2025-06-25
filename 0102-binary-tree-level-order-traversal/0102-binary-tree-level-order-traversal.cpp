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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        vector<vector<int>> res; 
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int t = q.size();
            vector<int> curLevel; 

            while(t--){
                TreeNode* tmp = q.front(); q.pop();
                curLevel.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }

            res.push_back(curLevel);
        }

        return res;
    }
};