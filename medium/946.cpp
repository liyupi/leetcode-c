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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        stack<int> mstack;
        while(i < pushed.size() && j < popped.size()) {
            while(i < pushed.size() && pushed[i] != popped[j]) {
                mstack.push(pushed[i]);
                i++;
            }
            i++;
            j++;
            while (!mstack.empty() && mstack.top() == popped[j]) {
                mstack.pop();
                j++;
            }
        }
        return mstack.empty();
    }
};

int main() {
    return 0;
}