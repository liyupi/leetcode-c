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
    int magicalString(int n) {
        if (!n) {
            return 0;
        }
        string str = "122";
        int posA = 2;
        char c = '1';
        while (str.length() <= n) {
            if (c == '1') {
                if (str[posA] == '1') {
                    str += '1';
                } else {
                    str += "11";
                }
                c = '2';
            } else {
                if (str[posA] == '1') {
                    str += '2';
                } else {
                    str += "22";
                }
                c = '1';
            }
            posA++;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (str[i] == '1') {
                res++;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}