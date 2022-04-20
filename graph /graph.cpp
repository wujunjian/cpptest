#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> seen(n, vector<int>(1 << n));

        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);
            seen[i][1 << i] = true;
        }
        int ans;
        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == (1 << n) - 1) {
                ans = dist;
                break;
            }


            for (int v : graph[u]) {
                int mask_v = mask | (1 << v);
                if (!seen[v][mask_v]) {
                    seen[v][mask_v] = true;
                    q.emplace(v, mask_v, dist + 1);
                }
            }
        }
        return ans;
    }
};