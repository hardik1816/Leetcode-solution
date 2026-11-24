
class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        vector<int> answer(n, 0);
        vector<int> parent(n, -1);
        vector<int> order;

        order.push_back(0);
        parent[0] = 0;

        int initialCost = 0;

        for (int i = 0; i < order.size(); i++) {
            int u = order[i];

            for (auto& [v, cost] : adj[u]) {
                if (v == parent[u]) {
                    continue;
                }

                parent[v] = u;
                initialCost += cost;
                order.push_back(v);
            }
        }

        answer[0] = initialCost;

        for (int u : order) {
            for (auto& [v, cost] : adj[u]) {
                if (parent[v] != u) {
                    continue;
                }

                if (cost == 0) {
                    answer[v] = answer[u] + 1;
                } else {
                    answer[v] = answer[u] - 1;
                }
            }
        }

        return answer;
    }
};
