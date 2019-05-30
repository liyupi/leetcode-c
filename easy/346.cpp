#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

class MovingAverage {
public:
    queue<int> q;
    int size;
    double sum = 0;

    /** Initialize your data structure here. */
    MovingAverage(int size) : size(size) {

    }

    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
};

int main() {
    return 0;
}