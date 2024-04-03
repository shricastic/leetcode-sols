class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        
        for (int num : arr) {
            countMap[num]++;
        }
        
        unordered_set<int> countSet;
        for (auto& pair : countMap) {
            if (countSet.count(pair.second) > 0) {
                return false; // If count is not unique
            }
            countSet.insert(pair.second);
        }
        
        return true;
    }
};
