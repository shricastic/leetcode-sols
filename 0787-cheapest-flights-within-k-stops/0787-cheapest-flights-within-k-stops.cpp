class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        
        for(auto& flight : flights){
            int u = flight[0], v = flight[1], c = flight[2];
            adjList[u].push_back({v, c});
        }
        
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        int stops = 0;
        
        while(!q.empty() && stops <= k){
            int size = q.size();
            
            for(int i=0 ; i<size ; i++){
                int node = q.front().first, price = q.front().second;
                q.pop();
                
                for(auto& [nextNode, cost] : adjList[node]){
                    if(cost+price < prices[nextNode]){
                        prices[nextNode] = cost+price;
                        q.push({nextNode, cost+price});
                    }
                }
            }
            stops++;
        }
        
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};