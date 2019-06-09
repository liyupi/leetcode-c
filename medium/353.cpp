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

class SnakeGame {
public:
    set<pair<int, int>> body;
    int width;
    int height;
    deque<pair<int, int>> tail;
    vector<vector<int>> &food;

    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>> &food) : width(width), height(height), food(food) {
        pair<int, int> p(0, 0);
        body.insert(p);
        tail.push_back(p);
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int headX = tail.front().first;
        int headY = tail.front().second;
        switch (direction[0]) {
            case 'U':
                headX--;
                break;
            case 'L':
                headY--;
                break;
            case 'R':
                headY++;
                break;
            default:
                headX++;
        }
        pair<int, int> p(headX, headY);
        const pair<int, int> tailNode = tail.back();
        if (headX >= 0 && headX < height && headY >= 0 && headY < width &&
            (!body.count(p) || tailNode == p)) {
            int pos = body.size() - 1;
            if (pos >= food.size() || food[pos][0] != headX || food[pos][1] != headY) {
                body.erase(tailNode);
                tail.pop_back();
            }
            tail.push_front(p);
            body.insert(p);
            return body.size() - 1;
        }
        return -1;
    }
};


int main() {
    return 0;
}