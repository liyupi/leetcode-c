#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
        int num = 0;
        int multi = 1;
        do {
            num += multi * !(N & 1);
            N >>= 1;
            multi *= 2;
        } while (N);
        return num;
    }
};

int main() {
    Solution solution;
    return 0;
}