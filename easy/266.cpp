#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> mmap;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            mmap[s[i] - 97]++;
        }
        bool odd = false;
        for (map<char, int>::iterator it = mmap.begin(); it != mmap.end() ; it++) {
            if (it->second & 1) {
                if (odd) {
                    return false;
                }
                odd = true;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}