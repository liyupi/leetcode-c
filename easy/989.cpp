#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        int len = A.size() - 1;
        stack<int> mStack;
        int carry = 0;
        while (len >= 0 || K) {
            int num;
            if (len >= 0) {
                num = A[len] + K % 10 + carry;
            } else {
                num = K % 10 + carry;
            }
            if (num > 10) {
                num -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            mStack.push(num);
            K /= 10;
            len--;
        }
        if (carry) {
            mStack.push(1);
        }
        vector<int> res;
        while (!mStack.empty()) {
            res.push_back(mStack.top());
            mStack.pop();
        }
        return res;
    }
};

int main() {

    return 0;
}