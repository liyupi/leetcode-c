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
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    vector<int> v;
    vector<int>::iterator it;

    NestedIterator(vector<NestedInteger> &nestedList) {
        init(nestedList);
        it = v.begin();
    }

    void init(const vector<NestedInteger> &nestedList) {
        int size = nestedList.size();
        for (int i = 0; i < size; ++i) {
            if (nestedList[i].isInteger()) {
                v.push_back(nestedList[i].getInteger());
            } else {
                init(nestedList[i].getList());
            }
        }
    }

    int next() {
        return *it++;
    }

    bool hasNext() {
        return it != v.end();
    }
};

int main() {
    return 0;
}