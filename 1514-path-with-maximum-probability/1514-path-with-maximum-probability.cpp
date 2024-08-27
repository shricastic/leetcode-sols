class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adjList(n);
        
        for(int i=0 ; i<edges.size() ; i++){
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adjList[u].push_back({v, prob});
            adjList[v].push_back({u, prob});
        }
        
        priority_queue<pair<double, int>> pq;
        vector<double> prob(n, 0.0);
        
        prob[start_node] = 1.0;
        pq.push({1.0, start_node});
        
        while(!pq.empty()){
            int node = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();
            
            for(auto& nd : adjList[node]){
                int nextNode = nd.first; 
                double nodeProb = nd.second;
                
                if(prob[nextNode] < currProb * nodeProb){
                    prob[nextNode] = currProb * nodeProb;
                    pq.push({prob[nextNode], nextNode});
                }
            }
        }
        
        return prob[end_node];        
    }
};