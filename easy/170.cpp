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

class TwoSum {
public:
    map<int, int> nums;

    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (map<int, int>::iterator it = nums.begin(); it != nums.end(); it++) {
            int val = value - it->first;
            if (val == it->first) {
                if (it->second > 1) {
                    return true;
                }
            } else if (nums.find(val) != nums.end()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    TwoSum twoSum;
    twoSum.add(0);
    cout << twoSum.find(0) << endl;
    return 0;
}