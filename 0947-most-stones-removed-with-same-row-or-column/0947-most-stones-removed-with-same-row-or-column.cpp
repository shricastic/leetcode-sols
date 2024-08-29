class Solution {
private:
    void dfs(int u, vector<vector<int>>& stones, vector<bool>& vis){
        vis[u] = true;
        
        for(int v=0 ; v<stones.size() ; v++){
            if(!vis[v] && (stones[v][0]==stones[u][0] || stones[v][1] == stones[u][1])){
                dfs(v, stones, vis);
            }
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<bool> vis(stones.size(), false);
        int groups = 0;
        
        for(int i=0 ; i<stones.size() ; i++){
            if(!vis[i]){
                dfs(i, stones, vis);
                groups++;
            }
        }
        
        return stones.size()-groups;
    }
};