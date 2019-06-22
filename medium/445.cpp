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
#include <ctime>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> s1, s2;
        ListNode *pos = l1;
        while (pos) {
            s1.push(pos->val);
            pos = pos->next;
        }
        pos = l2;
        while (pos) {
            s2.push(pos->val);
            pos = pos->next;
        }
        int carry = 0;
        ListNode *head = NULL;
        while (!s1.empty() || !s2.empty()) {
            int val1 = 0, val2 = 0;
            if (!s1.empty()) {
                val1 = s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                val2 = s2.top();
                s2.pop();
            }
            int val = val1 + val2 + carry;
            if (val > 9) {
                val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode *node = new ListNode(val);
            node->next = head;
            head  = node;
        }
        if (carry) {
            ListNode *node = new ListNode(1);
            node->next = head;
            head  = node;
        }
        return head;
    }
};

int main() {
    Solution solution;
    return 0;
}