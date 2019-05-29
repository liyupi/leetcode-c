#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &A) {
        vector<string> res;
        int count[26] = {0};
        int tmp[26] = {0};
        int len = A[0].size();
        for (int i = 0; i < len; ++i) {
            count[A[0][i] - 97]++;
        }
        len = A.size();
        for (int j = 1; j < len; ++j) {
            memset(tmp, 0, sizeof(tmp));
            int size = A[j].size();
            for (int i = 0; i < size; ++i) {
                tmp[A[j][i] - 97]++;
            }
            for (int i = 0; i < 26; ++i) {
                count[i] = min(count[i], tmp[i]);
            }
        }
        for (int i = 0; i < 26; ++i) {
            while (count[i]--) {
                string str;
                str += (char) (i + 97);
                res.push_back(str);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<string> data;
    data.push_back("bella");
    data.push_back("label");
    data.push_back("roller");
    solution.commonChars(data);
    return 0;
}