class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<int> indeg(N, 0), res;
        queue<int> q;

        vector<vector<int>> adjList(N);
        for(auto p: prerequisites) adjList[p[1]].push_back(p[0]);

        for(int u=0 ; u<N ; u++){
            for(int v : adjList[u]) indeg[v]++;
        }

        for(int i=0 ; i<N ; i++) if(indeg[i] == 0) q.push(i);

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int nbr : adjList[cur]){
                indeg[nbr]--;
                if(indeg[nbr] == 0) q.push(nbr);
            }

            res.push_back(cur);
        }

        if(res.size() == N) return res; 
        return {}; 
    }
};