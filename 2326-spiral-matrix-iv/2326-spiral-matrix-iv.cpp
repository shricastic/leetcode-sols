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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        
        while (head != nullptr) {
            // Traverse right
            for (int j = left; j <= right && head != nullptr; j++) {
                res[top][j] = head->val;
                head = head->next;
            }
            top++;
            
            // Traverse down
            for (int i = top; i <= bottom && head != nullptr; i++) {
                res[i][right] = head->val;
                head = head->next;
            }
            right--;
            
            // Traverse left
            for (int j = right; j >= left && head != nullptr; j--) {
                res[bottom][j] = head->val;
                head = head->next;
            }
            bottom--;
            
            // Traverse up
            for (int i = bottom; i >= top && head != nullptr; i--) {
                res[i][left] = head->val;
                head = head->next;
            }
            left++;
        }
        
        return res;
    }
};