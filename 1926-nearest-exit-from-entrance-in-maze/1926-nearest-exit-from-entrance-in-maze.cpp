class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = maze[0].size(), steps = 0;
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()){
            int qs = q.size();
            steps++;
            
            for(int i=0 ; i<qs ; i++){
                auto [r,c] = q.front();
                q.pop();
                
                for(auto [rd, cd] : directions){
                    int nr = rd+r, nc = cd+c;
                    
                    if(nr>=0 and nr<rows and nc>=0 and nc<cols and maze[nr][nc]=='.'){
                        if(nr==0 || nr==rows-1 || nc == 0 || nc==cols-1) return steps;
                        
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return -1;    
    }
};