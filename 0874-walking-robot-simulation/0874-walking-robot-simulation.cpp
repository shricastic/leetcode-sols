class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // To keep track of obstacles
        set<pair<int, int>> obstacleSet;
        for(auto ob : obstacles) obstacleSet.insert({ob[0], ob[1]});
        
        pair<int, int> cur = {0, 0};
        int cd = 0;  
        vector<pair<int, int>> dirn = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int maxDist = 0;
        
        for(int c : commands) {
            if(c == -1) cd = (cd + 1) % 4;
            else if(c == -2) cd = (cd + 3) % 4;
            else {
                while(c > 0) {
                    pair<int, int> tmp = cur;
                    
                    tmp.first += dirn[cd].first;
                    tmp.second += dirn[cd].second;
                    
                    if(obstacleSet.count(tmp) == 0) cur = tmp;
                    else break;
                    c--;
                }
            }
            maxDist = max(maxDist, cur.first * cur.first + cur.second * cur.second);
        }
        
        return maxDist;
    }
};
