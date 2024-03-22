# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.validate(root, float('-inf'), float('inf'))
        
        
    def validate(self, root: Optional[TreeNode], min_val: float, max_val: float)->bool:
        if root==None: return True
        
        if root.val <= min_val or root.val >= max_val:
            return False
        
        return self.validate(root.right, root.val, max_val) and self.validate(root.left, min_val, root.val)
        

        
        
        