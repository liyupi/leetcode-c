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

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node *p = node;
        if (node->right) {
            p = node->right;
            while(p->left) {
                p = p->left;
            }
            return p;
        }
        while(p->parent) {
            p = p->parent;
            if (p->val > node->val) {
                return p;
            }
        }
        return NULL;
    }
};

int main() {
    return 0;
}