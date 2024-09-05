class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0), m = rolls.size();
        
        int remSum = (mean*(m+n)) - sum;
        
        if (remSum < n || remSum > 6 * n) return {};
        
        vector<int> res(n, 1);
        remSum -= n;
        
        int idx = 0;
        while(remSum>0){
            int add = min(5, remSum);
            res[idx++] += add;
            remSum -= add;
        }
        
        return res;
    }
};