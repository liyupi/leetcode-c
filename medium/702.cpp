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

// Forward declaration of ArrayReader class.
class ArrayReader {
public:
    int get(int idx) const {
        return 0;
    }
};

class Solution {
public:
    int search(const ArrayReader &reader, int target) {
        int num;
        int count = 0;
        do {
            num = reader.get(count);
            if (num == target) {
                return count;
            }
            count++;
        } while (num < target);
        return -1;
    }
};

int main() {
    return 0;
}