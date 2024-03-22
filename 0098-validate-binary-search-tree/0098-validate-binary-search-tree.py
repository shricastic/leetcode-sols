# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder(self, root : Optional[TreeNode], nodeList: List[int]) -> List[int]:
        if(root==None): return nodeList
        
        self.inorder(root.left, nodeList)
        nodeList.append(root.val)
        self.inorder(root.right, nodeList)
        
        return nodeList
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        nodeList = self.inorder(root ,[])
        
        for x in range(1,len(nodeList)):
            if(nodeList[x]<=nodeList[x-1]):
                return False
        return True
        