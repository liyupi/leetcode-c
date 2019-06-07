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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<int, vector<TreeNode *>> mmap;

    vector<TreeNode *> allPossibleFBT(int N) {
        if (mmap.count(N)) {
            return mmap[N];
        }
        vector<TreeNode *> v;
        TreeNode *root = new TreeNode(0);
        if (N == 1) {
            v.push_back(root);
            mmap[N] = v;
            return v;
        }
        for (int i = 1; i <= N - 1; i += 2) {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(N - 1 - i);
            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    v.push_back(root);
                }
            }
        }
        mmap[N] = v;
        return v;
    }
};


int main() {
    Solution solution;
    solution.allPossibleFBT(5);
    return 0;
}