class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()){
            int room = q.front();
            q.pop();
            
            for(int key : rooms[room]){
                if(!vis[key]) vis[key] = true, q.push(key);
            }
        }
        
        for(bool visited : vis) if(!visited) return visited;
        
        return true;
    }
};