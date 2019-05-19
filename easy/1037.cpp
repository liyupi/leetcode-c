#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>> &points) {
        return (points[0][0] - points[1][0]) * (points[1][1] - points[2][1]) !=
               (points[1][0] - points[2][0]) * (points[0][1] - points[1][1]);
    }
};

int main() {
    Solution solution;
    return 0;
}