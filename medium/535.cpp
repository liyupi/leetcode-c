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
    int count = 0;
    map<int, string> mmap;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mmap[count] = longUrl;
        return "http://" + to_string(count++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int key = stol(shortUrl.substr(7, shortUrl.length() - 7));
        return mmap[key];
    }
};

int main() {
    return 0;
}