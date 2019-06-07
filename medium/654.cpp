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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return preOrder(nums, 0, nums.size());
    }

    TreeNode *preOrder(vector<int> &nums, int left, int right) {
        if (left == right) {
            return NULL;
        }
        int maxNum = nums[left];
        int maxPos = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxPos = i;
            }
        }
        TreeNode *root = new TreeNode(maxNum);
        root->left = preOrder(nums, left, maxPos);
        root->right = preOrder(nums, maxPos + 1, right);
        return root;
    }
};

int main() {
    return 0;
}