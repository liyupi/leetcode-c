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

class StringIterator {
public:
    vector<char> chars;
    vector<long long> counts;
    int count = 0;
    int pos = 0;

    StringIterator(string compressedString) {
        compressedString += '.';
        int count = 0;
        char c = compressedString[0];
        int len = compressedString.length();
        for (int i = 0; i < len; ++i) {
            if (isdigit(compressedString[i])) {
                count = count * 10 + compressedString[i] - 48;
            } else {
                if (count) {
                    counts.push_back(count);
                    chars.push_back(c);
                }
                c = compressedString[i];
                count = 0;
            }
        }
    }

    char next() {
        if (hasNext()) {
            char c = chars[pos];
            count++;
            if (count == counts[pos]) {
                count = 0;
                pos++;
            }
            return c;
        }
        return ' ';
    }

    bool hasNext() {
        return pos < counts.size();
    }
};

int main() {
    return 0;
}