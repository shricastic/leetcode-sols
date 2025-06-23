class Solution {
private:
    vector<int> vis;
    stack<int> st;
    bool dfs(int node, vector<vector<int>>& adjList){
        if(vis[node] == 1) return true;
        if(vis[node] == 2) return false;

        vis[node] = 1;
       
        for(auto n: adjList[node]){
            if(dfs(n, adjList)) return true;
        }

        vis[node] = 2;

        st.push(node);
        return false;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(n);
        for(auto& p : prerequisites){
            adjList[p[1]].push_back(p[0]);
        }

        vis.resize(n, 0);
        for(int i=0 ; i<n ; i++){
            if(vis[i] == 0){
                if(dfs(i, adjList)) return {};
            }
        }
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top()); st.pop();
        }

        return res;
    }
};