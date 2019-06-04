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
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        for (int i = 0; i < size; ++i) {
            if (citations[i] >= size - i) {
                return size - i;
            }
        }
        return 0;
    }
};

int main() {
    return 0;
}