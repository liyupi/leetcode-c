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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        if (!timeSeries.size()) {
            return res;
        }
        int last = timeSeries[0] + duration;
        int left = timeSeries[0];
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] > last) {
                res += last - left;
                left = timeSeries[i];
            }
            last = timeSeries[i] + duration;
        }
        res += last - left;
        return res;
    }
};

int main() {
    return 0;
}