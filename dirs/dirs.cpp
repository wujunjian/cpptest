
/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

 // @lc code=start

#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution
{
public:
    int lengthLongestPath(string input)
    {

        vector<vector<string> > dirs;
        int ans = 0;

        int depth = 0;
        string tmp;

        auto f = [&]() -> void
        {
            if (dirs.size() <= depth)
            {
                dirs.push_back(vector<string>());
            }
            dirs[depth].push_back(tmp);

            if (tmp.find(".") != std::string::npos)
            {
                int length = 0;
                for (auto& v : dirs)
                {
                    if (depth < 0) {
                        break;
                    }
                    --depth;
                    length += v.back().size();
                }
                if (tmp.back() == '\n')
                {
                    length -= 1;
                }
                ans = ans > length ? ans : length;
            }
            tmp.clear();
            depth = 0;
        };

        for (auto& c : input)
        {

            if (c == '\t')
            {
                ++depth;
                continue;
            }

            tmp.push_back(c);
            if (c == '\n')
            {
                f();
            }
        }

        f();

        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") << endl;
}