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

using namespace std;

/**
 * https://blog.csdn.net/jmspan/article/details/51093343
 */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        vector<int> starts;
        vector<int> ends;
        int size = intervals.size();
        for (int i = 0; i < size; ++i) {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int res = 0;
        int i = 0, j = 0;
        int count = 0;
        while(i < size && j < size) {
            if (starts[i] < ends[j]) {
                count++;
                res = max(res, count);
                i++;
            } else {
                count--;
                j++;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}