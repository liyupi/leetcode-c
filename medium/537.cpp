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
    string complexNumberMultiply(string a, string b) {
        int posA = a.find('+');
        int posB = b.find('+');
        int rnumA = stol(a.substr(0, posA));
        int rnumB = stol(b.substr(0, posB));
        int xnumA = stol(a.substr(posA + 1, a.length() - posA - 2));
        int xnumB = stol(b.substr(posB + 1, b.length() - posB - 2));
        int r = rnumA * rnumB - xnumA * xnumB;
        int x = rnumA * xnumB + rnumB * xnumA;
        stringstream ss;
        ss << r << "+" << x << "i";
        return ss.str();
    }
};

int main() {
    return 0;
}