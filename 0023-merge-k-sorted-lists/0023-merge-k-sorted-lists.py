# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        allvalues = []
        
        for head in lists:
            while head:
                allvalues.append(head.val)
                head = head.next
                
        allvalues.sort()
        
        dummy = ListNode()
        curr = dummy        
        for val in allvalues:
            curr.next = ListNode(val)
            curr = curr.next
            
        return dummy.next
            
        