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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while(curr != nullptr) n++, curr = curr->next;
        
        int rem = n%k, len = n/k;
        vector<ListNode*> res(k, nullptr);
        curr = head;
        
        for(int i=0 ; i<k && curr!=nullptr ; i++){
            res[i] = curr;
            
            int partLen = len + (i<rem ? 1 : 0);
            for(int j=0 ; j<partLen-1 ; j++){
                curr = curr->next;
            }
            
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }
        
        
        return res;
    }
};