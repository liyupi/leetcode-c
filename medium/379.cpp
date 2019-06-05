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

class PhoneDirectory {
public:
    set<int> used;
    int maxNumbers;

    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : maxNumbers(maxNumbers) {

    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (used.size() == maxNumbers) {
            return -1;
        }
        for (int i = 0; i < maxNumbers; ++i) {
            if (!used.count(i)) {
                used.insert(i);
                return i;
            }
        }
        return -1;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return !used.count(number);
    }

    /** Recycle or release a number. */
    void release(int number) {
        used.erase(number);
    }
};

int main() {
    return 0;
}