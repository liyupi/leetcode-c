#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>> &board) {
        int x = -1, y;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x != -1) {
                break;
            }
        }
        char c[4] = "000";
        for (int i = 0; i < x; ++i) {
            if (board[i][y] != '.') {
                c[0] = board[i][y];
            }
        }
        for (int i = x + 1; i < 8; ++i) {
            if (board[i][y] != '.') {
                c[1] = board[i][y];
                break;
            }
        }
        for (int j = 0; j < y; ++j) {
            if (board[x][j] != '.') {
                c[2] = board[x][j];
            }
        }
        for (int j = y + 1; j < 8; ++j) {
            if (board[x][j] != '.') {
                c[3] = board[x][j];
                break;
            }
        }
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            if (c[i] == 'p') {
                res++;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}