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

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, int> mmap;
        int size = B.size();
        for (int i = 0; i < size; ++i) {
            mmap[B[i]] = i;
        }
        for (int i = 0; i < size; ++i) {
            B[i] = mmap[A[i]];
        }
        return B;
    }
};

int main() {
    Solution solution;
    return 0;
}