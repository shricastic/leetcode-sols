class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> q; // {time, node}
        vector<int> first(n + 1, INT_MAX);
        vector<int> second(n + 1, INT_MAX);

        q.push({0, 1});
        first[1] = 0;

        while (!q.empty()) {
            auto [currentTime, node] = q.front();
            q.pop();

            int newTime = currentTime;
            if ((currentTime / change) % 2 == 1) { 
                newTime += change - (currentTime % change);
            }
            newTime += time; 

            for (int neighbor : adj[node]) {
                if (newTime < first[neighbor]) {
                    second[neighbor] = first[neighbor];
                    first[neighbor] = newTime;
                    q.push({newTime, neighbor});
                } else if (newTime > first[neighbor] && newTime < second[neighbor]) {
                    second[neighbor] = newTime;
                    q.push({newTime, neighbor});
                }
            }
        }

        return second[n] == INT_MAX ? -1 : second[n];
    }
};
