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

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string str;
        int size = strs.size();
        for (int i = 0; i < size; ++i) {
            str += to_string(strs[i].length()) + ',' + strs[i];
        }
        return str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int len = s.length();
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            while (s[i] != ',') {
                sum = sum * 10 + s[i] - 48;
                i++;
            }
            res.push_back(s.substr(i + 1, sum));
            i += sum;
            sum = 0;
        }
        return res;
    }
};

int main() {
    return 0;
}