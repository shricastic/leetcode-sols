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
    void swap(ListNode* node){
        if(node==NULL || node->next==NULL){
            return;
        }
        
        int tmp = node->val;
        node->val = node->next->val;
        node->next->val = tmp;
        
        swap(node->next->next);
    }
    
    
    ListNode* swapPairs(ListNode* head) {
        swap(head);
        
        return head;
    }
};