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
    int numComponents(ListNode *head, vector<int> &G) {
        set<int> mset;
        for (int i = 0; i < G.size(); ++i) {
            mset.insert(G[i]);
        }
        int res = 0;
        bool flag = false;
        while(head) {
            if (mset.count(head->val)) {
                if (!flag) {
                    res++;
                }
                flag = true;
            } else {
                flag = false;
            }
            head = head->next;
        }
        return res;
    }
};

int main() {
    return 0;
}