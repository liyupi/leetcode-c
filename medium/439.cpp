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
    string parseTernary(string expression) {
        stack<char> op;
        stack<char> val;
        for (int i = expression.length() - 1; i >= 0; --i) {
            if (isdigit(expression[i]) || expression[i] == 'T' || expression[i] == 'F') {
                val.push(expression[i]);
            } else if (expression[i] == '?') {
                --i;
                op.push(expression[i]);
            }
            while (val.size() >= 2 && op.size() >= 1) {
                char c = op.top();
                op.pop();
                char val1 = val.top();
                val.pop();
                char val2 = val.top();
                val.pop();
                if (c == 'T') {
                    val.push(val2);
                } else {
                    val.push(val1);
                }
            }
        }
        return string(1, val.top());
    }
};

int main() {
    return 0;
}