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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return {-1, -1};
        }
        
        
        ListNode *curr = head->next, *prev= head, *next=curr->next;
        int position = 1;
        vector<int> criticalPoints;
        
        while(next != nullptr){
            if((curr->val<prev->val && curr->val<next->val) || 
               (curr->val>prev->val && curr->val>next->val)
              ){
                criticalPoints.push_back(position);
            }
            
            prev = curr;
            curr = next;
            next = curr->next;
            position++;
        }
        
        if(criticalPoints.size()<2){
            return {-1, -1};
        }
        
        int minDist = INT_MAX;
        int maxDist = INT_MIN;
        
        for(int i=1 ; i<criticalPoints.size() ; i++){
            int tmpDist = criticalPoints[i] - criticalPoints[i-1];
            
            minDist = min(minDist, tmpDist);
            maxDist = max(maxDist, criticalPoints.back() - criticalPoints.front());
        }
        
        return vector<int> {minDist, maxDist};       
    }
};