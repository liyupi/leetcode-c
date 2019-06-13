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

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *head;
    Node *pre;
    Node *pos;

    Node *treeToDoublyList(Node *root) {
        if (!root) {
            return root;
        }
        inOrder(root);
        pos->right = head;
        head->left = pos;
        return head;
    }

    void inOrder(Node *root) {
        if (root->left) {
            inOrder(root->left);
        }
        if (!head) {
            head = root;
        }
        pos = root;
        if (pre) {
            pre->right = pos;
            pos->left = pre;
        }
        pre = pos;
        if (root->right) {
            inOrder(root->right);
        }
    }
};


int main() {
    return 0;
}