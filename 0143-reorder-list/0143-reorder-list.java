class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null || head.next.next == null) {
            return; // Handling cases with 0, 1, or 2 nodes
        }
        
        // Step 1: Find the middle of the linked list
        ListNode slow = head;
        ListNode fast = head;
        
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Step 2: Reverse the second half of the linked list
        ListNode prev = null;
        ListNode curr = slow.next;
        
        while (curr != null) {
            ListNode nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow.next = null; // Break the link
        
        // Step 3: Merge the two halves of the linked list
        ListNode p1 = head;
        ListNode p2 = prev;
        
        while (p1 != null && p2 != null) {
            ListNode nextP1 = p1.next;
            ListNode nextP2 = p2.next;
            
            p1.next = p2;
            p2.next = nextP1;
            
            p1 = nextP1;
            p2 = nextP2;
        }
    }
}
