class Solution {
private:
    void dfs(int v, vector<vector<int>>& matrix, vector<bool>& vis){
        vis[v] = true;
        
        for(int u=0; u<matrix[v].size() ; u++){
            if(matrix[v][u] == 1 && !vis[u]){
                dfs(u, matrix, vis);
            }
        }
        
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        vector<bool> vis(isConnected.size(), false);
        
        for(int v = 0 ; v < isConnected.size() ; v++){
            if(!vis[v]){
                dfs(v, isConnected, vis);
                provinces++;
            }
        }
        
        return provinces;
    }
};