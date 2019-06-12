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

class Solution {
public:
    int numTilePossibilities(string tiles) {
        set<string> mset;
        sort(tiles.begin(), tiles.end());
        int res = 0;
        do {
            for (int i = 0; i < tiles.length(); ++i) {
                mset.insert(tiles.substr(0, i + 1));
            }
        } while (next_permutation(tiles.begin(), tiles.end()));
        return mset.size();
    }
};

int main() {
    return 0;
}