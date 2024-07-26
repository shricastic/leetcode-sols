class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            graph[u].emplace_back(v, weight);
            graph[v].emplace_back(u, weight);
        }

        auto countNeighborsWithinDistance = [&](int start) -> int {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.emplace(0, start);
            set<int> visited;

            while (!pq.empty()) {
                auto [dist, node] = pq.top();
                pq.pop();
                if (!visited.count(node)) {
                    visited.insert(node);
                    for (const auto& [neighbor, weight] : graph[node]) {
                        int newDist = dist + weight;
                        if (newDist <= distanceThreshold) {
                            pq.emplace(newDist, neighbor);
                        }
                    }
                }
            }
            return visited.size() - 1;
        };

        int minNeighbors = n;
        int result = -1;

        for (int start = 0; start < n; ++start) {
            int neighbors = countNeighborsWithinDistance(start);
            if (neighbors <= minNeighbors) {
                minNeighbors = neighbors;
                result = start;
            }
        }

        return result;
    }
};
