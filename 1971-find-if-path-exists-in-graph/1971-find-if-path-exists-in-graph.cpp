class Solution {
private:
    bool dfs(int u, int dest, const vector<vector<int>>& adjList, vector<bool>& vis) {
        if (u == dest) return true;
        vis[u] = true;
        
        for (int v : adjList[u]) {
            if (!vis[v]) {
                if (dfs(v, dest, adjList, vis)) return true;
            }
        }
        
        return false;
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(n, false);
        return dfs(source, destination, adjList, vis);
    }
};
