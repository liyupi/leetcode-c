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

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int a[100001];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < nums.size(); ++i) {
            a[nums[i] + 50000]++;
        }
        int pos = 0;
        for (int i = 0; i <= 100000; ++i) {
            while (a[i]--) {
                nums[pos++] = i - 50000;
            }
        }
        return nums;
    }
};

int main() {
    return 0;
}