# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        currNode, prevNode = head, None
        
        while currNode:
            currNode.next, prevNode, currNode = prevNode, currNode, currNode.next
            
        return prevNode
    