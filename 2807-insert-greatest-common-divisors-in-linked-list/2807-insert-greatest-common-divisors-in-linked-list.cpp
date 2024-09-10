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
private:
    int gcd(int a, int b){
        if(b == 0) return a;
        if(b > a) return gcd(b, a);
        
        return gcd(b, a%b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *cur = head, *nxt = head->next;
        
        if(nxt==nullptr) return head;
        
        while(nxt != nullptr){
            int n = gcd(cur->val, nxt->val);
            ListNode *tmp = new ListNode(n);
            
            cur->next = tmp;
            tmp->next = nxt;
            cur = nxt;
            nxt = cur->next;
        }
        
        return head;
    }
};