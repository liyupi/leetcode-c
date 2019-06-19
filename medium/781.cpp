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
    int numRabbits(vector<int> &answers) {
        map<int, int> mmap;
        int res = 0;
        for (int i = 0; i < answers.size(); ++i) {
            mmap[answers[i]]++;
        }
        for (auto entry : mmap) {
            while(entry.second - 1 > entry.first) {
                res += entry.first + 1;
                entry.second -= entry.first + 1;
            }
            res += entry.first + 1;
        }
        return res;
    }
};

int main() {
    return 0;
}