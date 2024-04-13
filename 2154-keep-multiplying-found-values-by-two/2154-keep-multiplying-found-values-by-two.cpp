class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set s(begin(nums), end(nums));
        while (s.count(original))
            original *= 2;
        return original;
    }
};
