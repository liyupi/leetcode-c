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


class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    int depthSum(vector<NestedInteger> &nestedList) {
        return depthSum(nestedList, 1);
    }
    int depthSum(vector<NestedInteger> &nestedList, int depth) {
        int sum = 0;
        int size = nestedList.size();
        for (int i = 0; i < size; ++i) {
            if (nestedList[i].isInteger()) {
                sum += nestedList[i].getInteger() * depth;
            } else {
                vector<NestedInteger> tmp = nestedList[i].getList();
                sum += depthSum(tmp, depth + 1);
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    return 0;
}