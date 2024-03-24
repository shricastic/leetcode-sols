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
    bool isPalindrome(ListNode* head) {
        std::list<int> ls = {};
        
        while (head!=nullptr){
            int val = head->val;
            ls.push_back(val);
            head = head->next;
        }
        
        std::list<int> rls(ls.rbegin(), ls.rend());
            
        return ls==rls;      
        
    }
};