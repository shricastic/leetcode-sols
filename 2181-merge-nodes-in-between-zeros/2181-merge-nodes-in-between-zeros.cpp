/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* newHead = new ListNode(0);
        ListNode* newNode = newHead;
        int sum = 0;
        
        while(curr != nullptr){
            if(curr->val==0){
                newNode->next = new ListNode(sum);
                newNode = newNode->next;
                sum = 0;                
            } else {
                sum += curr->val;
            }
            
            curr = curr->next;
        }
        
        return newHead->next;
        
    }
};