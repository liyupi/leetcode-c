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
    map<int, int> mmap;
    int maxPos = 0;

    int depthSumInverse(vector<NestedInteger> &nestedList) {
        depthSumInverse(nestedList, 0);
        int sum = 0;
        for (auto it = mmap.begin(); it != mmap.end(); ++it) {
            sum += (maxPos - it->first + 1) * it->second;
        }
        return sum;
    }

    void depthSumInverse(const vector<NestedInteger> &nestedList, int pos) {
        maxPos = max(maxPos, pos);
        int size = nestedList.size();
        for (int i = 0; i < size; ++i) {
            if (nestedList[i].isInteger()) {
                mmap[pos]+= nestedList[i].getInteger();
            } else {
                depthSumInverse(nestedList[i].getList(), pos + 1);
            }
        }
    }
};

int main() {
    return 0;
}