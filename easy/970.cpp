#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> mset;
        vector<int> res;
        if (x == 1 && y == 1) {
            if (bound > 1) {
                res.push_back(2);
            }
            return res;
        }
        if (x < y) {
            swap(x, y);
        }
        if (y == 1) {
            for (int i = 1; i <= bound; i *= x) {
                res.push_back(i + 1);
            }
            return res;
        }
        int i = 1, j = 1;
        int num = 0;
        while (true) {
            while (true) {
                num = i + j;
                if (num > bound) {
                    break;
                }
                mset.insert(num);
                j *= y;
            }
            i *= x;
            if (i > num) {
                break;
            }
            j = 1;
        }
        res.assign(mset.begin(), mset.end());
        return res;
    }
};

int main() {
    Solution solution;
    solution.powerfulIntegers(2, 1, 10);
    return 0;
}