#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <cmath>

using namespace std;

class TicTacToe {
public:
    vector<vector<int>> v;
    int n;

    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n) {
        for (int i = 0; i < n; ++i) {
            vector<int> subV;
            for (int j = 0; j < n; ++j) {
                subV.push_back(0);
            }
            v.push_back(subV);
        }
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        bool flag = true;
        v[row][col] = player;
        for (int i = 0; i < n; ++i) {
            if (v[i][col] != player) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return player;
        }
        flag = true;
        for (int i = 0; i < n; ++i) {
            if (v[row][i] != player) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return player;
        }
        if (row == col) {
            flag = true;
            for (int i = 0; i < n; ++i) {
                if (v[i][i] != player) {
                    flag = false;
                    break;
                }
            }
        }
        if (row + col == n - 1) {
            flag = true;
            for (int i = 0; i < n; ++i) {
                if (v[i][n - i - 1] != player) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            return player;
        }
        return 0;
    }
};

int main() {
    TicTacToe *toe = new TicTacToe(3);
    toe->move(0, 0, 1);
    return 0;
}