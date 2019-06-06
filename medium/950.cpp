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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = deck.size() - 1; i >= 0; --i) {
            q.push(deck[i]);
            if (!i) {
                break;
            }
            int val = q.front();
            q.pop();
            q.push(val);
        }
        vector<int> res(deck.size());
        int count = deck.size() - 1;
        while(!q.empty()) {
            res[count--] = q.front();
            q.pop();
        }
        return res;
    }
};

int main() {
    return 0;
}