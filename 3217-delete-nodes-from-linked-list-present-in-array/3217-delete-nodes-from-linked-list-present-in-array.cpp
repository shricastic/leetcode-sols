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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set(nums.begin(), nums.end());
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        
        while(head!= nullptr){
            if(set.count(head->val) == 0){
                ListNode* tmp = new ListNode(head->val);
                cur->next = tmp;
                cur = cur->next;
            }
            
            head = head->next;
        }
        
        return dummy->next;
    }
};