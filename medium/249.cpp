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
 * ELF HASH
 */
class Solution {
public:
    unordered_map<unsigned int, vector<string>> mmap;

    vector<vector<string>> groupStrings(vector<string> &strings) {
        int size = strings.size();
        for (int i = 0; i < size; ++i) {
            mmap[hash(strings[i])].push_back(strings[i]);
        }
        vector<vector<string>> res;
        for (unordered_map<unsigned int, vector<string>>::iterator it = mmap.begin(); it != mmap.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }

    unsigned int hash(string &str) {
        int len = str.length();
        unsigned int val = len;
        unsigned int x = 0;
        for (int i = 1; i < len; ++i) {
            val = (val << 4) + (26 + str[i] - str[0]) % 26;     //1
            if ((x = val & 0xf0000000)) {
                val ^= x >> 24;   //影响5-8位，杂糅一次   3
                val &= ~x;   //清空高四位    4
            }
        }
        return (val & 0x7fffffff);
    }
};

int main() {
    return 0;
}