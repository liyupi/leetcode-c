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
    void reverseWords(vector<char> &str) {
        int size = str.size();
        int len = size / 2;
        int left = 0;
        reverse(str, left, size);
        for (int i = 0; i < size; ++i) {
            if (str[i] == ' ') {
                reverse(str, left, i);
                left = i + 1;
            }
        }
        reverse(str, left, size);
    }

    void reverse(vector<char> &str, int left, int right) {
        while (left < right) {
            swap(str[left++], str[--right]);
        }
    }
};

int main() {
    Solution so;
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back(' ');
    chars.push_back('c');
    chars.push_back('d');
    so.reverseWords(chars);
    return 0;
}