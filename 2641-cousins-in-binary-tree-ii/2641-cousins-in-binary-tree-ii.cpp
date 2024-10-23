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
    int sum[100001]={0}, h=0;
    
    void findLevelSum(TreeNode* root, int level){
        if(!root) return;
        if(level>=h) h++;
        
        sum[level] += root->val;
        
        findLevelSum(root->left, level+1);
        findLevelSum(root->right, level+1);
    }
    
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(level+1<=h){
            int x = sum[level+1];            
            bool l = (root->left), r = (root->right);
            
            x -= l?root->left->val :0;
            x -= r?root->right->val :0;
            
            if(l) root->left->val = x;
            if(r) root->right->val = x;
        }
        
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        findLevelSum(root, 0);
        root->val = 0;
        dfs(root, 0);
        
        return root;
    }
};