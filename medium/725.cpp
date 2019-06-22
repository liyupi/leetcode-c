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
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        int size = 0;
        ListNode *pos = root;
        while (pos) {
            pos = pos->next;
            size++;
        }
        int n = size / k;
        int left = size % k;
        vector<ListNode *> res(k);
        pos = root;
        ListNode *pre = pos;
        for (int i = 0; i < k; ++i) {
            if (!pos) {
                break;
            }
            res[i] = pos;
            int maxJ = n + (left-- > 0);
            for (int j = 0; j < maxJ; ++j) {
                pre = pos;
                pos = pos->next;
            }
            pre->next = NULL;
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}