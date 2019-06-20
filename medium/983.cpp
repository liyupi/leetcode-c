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
#include <ctime>

using namespace std;

class Solution {
public:
    const int INF = 0xfffffff;
    map<int, int> mmap;

    int mincostTickets(vector<int> &days, vector<int> &costs) {
        return mincostTickets(days, costs, 0);
    }

    int mincostTickets(vector<int> &days, vector<int> &costs, int pos) {
        if (pos == days.size()) {
            return 0;
        }
        if (mmap[pos]) {
            return mmap[pos];
        }
        int minNum = INF;
        minNum = min(minNum, costs[0] + mincostTickets(days, costs, pos + 1));
        int i = pos;
        while (i < days.size() && days[i] < days[pos] + 7) {
            i++;
        }
        minNum = min(minNum, costs[1] + mincostTickets(days, costs, i));
        i = pos;
        while (i < days.size() && days[i] < days[pos] + 30) {
            i++;
        }
        minNum = min(minNum, costs[2] + mincostTickets(days, costs, i));
        mmap[pos] = minNum;
        return minNum;
    }
};

int main() {
    return 0;
}