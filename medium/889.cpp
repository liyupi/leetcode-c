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
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        return constructFromPrePost(pre, post, 0, pre.size(), 0, post.size());
    }

    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post, int left1, int right1, int left2, int right2) {
        if (left1 == right1) {
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[left1]);
        if (left1 == right1 - 1) {
            return root;
        }
        int pos = -1;
        for (int i = left2; i < right2; ++i) {
            if (pre[left1 + 1] == post[i]) {
                pos = i;
            }
        }
        root->left = constructFromPrePost(pre, post, left1 + 1, left1 + 1 + pos - left2 + 1, left2, pos + 1);
        root->right = constructFromPrePost(pre, post, left1 + 1 + pos - left2 + 1, right1, pos + 1, right2);
        return root;
    }
};


int main() {
    return 0;
}