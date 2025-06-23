class Solution {
private:
    vector<int> vis, res;
    bool cycle = false;
    void dfs(int node, vector<vector<int>>& adjList){
        if(cycle || vis[node]!= 0) return;

        vis[node] = 1;

        for(int nbr: adjList[node]){
            if(vis[nbr] == 1){
                cycle = true;
                return;
            }
            dfs(nbr, adjList);
        }

        vis[node] = 2;
        res.push_back(node);
    }


public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vis.resize(N, 0); 
        vector<vector<int>> adjList(N);

        for(auto p: prerequisites){
            adjList[p[1]].push_back(p[0]);
        }

        for(int i=0 ; i<N ; i++){
            if(vis[i] == 0) dfs(i, adjList);
            if(cycle) return {};
        }

        reverse(res.begin(), res.end());

        return res;
    }
};