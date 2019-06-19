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
    vector<int> beautifulArray(int N) {
        vector<int> v;
        v.push_back(1);
        while (v.size() < N) {
            vector<int> next;
            for (int i = 0; i < v.size(); ++i) {
                next.push_back(2 * v[i] - 1);
            }
            for (int i = 0; i < v.size(); ++i) {
                next.push_back(2 * v[i]);
            }
            v = next;
        }
        vector<int> res;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] <= N) {
                res.push_back(v[i]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}