class Solution {
private:
    int cnt = 0;
    
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adjList, vector<bool>& vis){
        vis[node] = true;
        
        for(auto& [next, sign] : adjList[node]){
            if(!vis[next]){
                cnt += sign;
                dfs(next, node, adjList, vis);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adjList(n);
        
        for(auto& c : connections){
            adjList[c[0]].push_back({c[1], 1});
            adjList[c[1]].push_back({c[0], 0});
        }
        
        vector<bool> vis(n, false);
        dfs(0, -1, adjList, vis);
        return cnt;
    }
};