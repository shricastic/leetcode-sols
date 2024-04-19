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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ls;
        
        for(int i=0 ; i<lists.size() ; i++){
            ListNode* head = lists[i];
            while(head != nullptr){
                ls.push_back(head->val);
                head = head->next;
            }
        }
        
        sort(ls.begin(), ls.end());
        
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        
        for(int i : ls){
            ListNode* newNode = new ListNode(i);
            head->next = newNode;
            head = head->next;
        }
        
        return dummy->next;
    }
};