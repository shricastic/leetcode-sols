class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start, end;
        
        for(auto interval : intervals){
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        
        int itr = 0, cnt = 0;
        
        for(int i : start) i>end[itr] ? itr++ : cnt++;
        
        return cnt;
    }
};