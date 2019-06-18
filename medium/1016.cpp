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
    bool queryString(string S, int N) {
        char *str = nullptr;
        for (int i = 1; i <= N; ++i) {
            if (S.find(toBinary(i)) == string::npos) {
                return false;
            }
        }
        return true;
    }

    string toBinary(int N) {
        string s;
        while(N) {
            int left = N % 2;
            s = (char)(left + 48) + s;
            N /= 2;
        }
        return s;
    }
};

int main() {
    return 0;
}