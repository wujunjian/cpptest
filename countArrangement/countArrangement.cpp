#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> match;
        vector<int> vis;
        int num = 0;

        function<void(int, int)> backtrack = [&](int index, int n) -> void {
            if (index == n + 1) {
                num++;
                return;
            }
            for (auto& x : match[index]) {
                if (!vis[x]) {
                    vis[x] = true;
                    backtrack(index + 1, n);
                    vis[x] = false;
                }
            }
        };
        vis.resize(n + 1);
        match.resize(n + 1);

        for (int i = 1;i <= n;++i) {
            for (int j = 1;j <= n;++j) {
                if (i % j == 0 || j % i == 0) {
                    match[i].push_back(j);
                }
            }
        }
        backtrack(1, n);
        return num;
    }
};