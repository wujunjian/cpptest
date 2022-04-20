#include <vector>
#include <iostream>


using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unsigned int> line(9, 0x1FF);
        vector<unsigned int> column(9, 0x1FF);
        vector<unsigned int> littleboard(9, 0x1FF);
        unsigned int x = 0, y = 0;
        for (auto& l : board) {
            for (char b : l) {
                int littleboardidx = x / 3 * 3 + y / 3;
                // cout << "x:" << x << " y:" << y << " b:" << b << " line:" <<
                //     hex << line[x] << " column:" << column[y] <<
                //     " littleboard:" << littleboardidx << ":" << littleboard[littleboardidx] << endl;
                if (b == '.') {
                    y++;
                    continue;
                }
                int n = 0x1 << (b - '1');
                if ((line[x] & n) != 0) {
                    line[x] = line[x] ^ n;
                }
                else {
                    return false;
                }

                if ((column[y] & n) != 0) {
                    column[y] = column[y] ^ n;
                }
                else {
                    return false;
                }

                if ((littleboard[littleboardidx] & n) != 0) {
                    littleboard[littleboardidx] = littleboard[littleboardidx] ^ n;
                }
                else {
                    cout << "debug:" << hex << (littleboard[littleboardidx] & n) << endl;
                    return false;
                }
                y++;
            }
            x++;
            y = 0;
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board{
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

    Solution s;
    cout << "result:" << s.isValidSudoku(board) << endl;
    return 0;
}