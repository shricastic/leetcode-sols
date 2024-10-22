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
    void dfs(TreeNode* root, vector<long long>& levels, int curLevel){
        if(root == nullptr) return;
        if (curLevel >= levels.size()) levels.push_back(0);
        
        levels[curLevel] += root->val;
        
        dfs(root->left, levels, curLevel+1);
        dfs(root->right, levels, curLevel+1);
    }
    
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // declare array as levels, each index will store the sum at that level
        vector<long long> levels;
        
        //traverse the tree using dfs and depth will denote level and add the value to each level index in level array
        dfs(root, levels, 0);
    
        //check if k is greater than levels
        if (k > levels.size()) return -1;

        //return the max in the level array
        sort(levels.begin(), levels.end(), std::greater<long long>()); 
        return levels[k-1];
    }
};