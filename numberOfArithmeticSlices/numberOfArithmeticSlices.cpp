#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<unordered_map<long long, int>> f(n);
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < i;++j) {
                long long d = 1LL * nums[i] - nums[j];
                auto iter = f[j].find(d);
                int cnt = iter == f[j].end() ? 0 : iter->second;
                ans += cnt;
                f[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};