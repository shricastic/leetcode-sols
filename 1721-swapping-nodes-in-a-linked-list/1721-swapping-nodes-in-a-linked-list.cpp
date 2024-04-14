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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node = head;
        ListNode* fp = node;
        int size = 1;
        
        while(node!=NULL){
            if(size==k){
                fp = node;
            }
            
            node = node->next;
            size++;
        }
        
        node = head;
        int cnt = 1;
        while(node!=NULL){
            if(cnt == size-k){
                int tmp = fp->val;
                fp->val = node->val;
                node->val = tmp;
            }
            
            node = node->next;
            cnt++;
        }
        
        
        return head;        
    }
};