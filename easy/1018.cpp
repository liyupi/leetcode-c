#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:

    vector<bool> prefixesDivBy5(vector<int> &A) {
        int num = 0;
        int len = A.size();
        vector<bool> res;
        for (int i = 0; i < len; ++i) {
            num <<= 1;
            num += A[i];
            num %= 10;
            res.push_back(num % 5 == 0);
        }
        return res;
    }
};

int main() {

    return 0;
}