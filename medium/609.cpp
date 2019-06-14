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

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> mmap;
        for (int i = 0; i < paths.size(); ++i) {
            int len = paths[i].length();
            int pathPos = paths[i].find(' ');
            string path = paths[i].substr(0, pathPos);
            for (int j = pathPos + 1; j < len; ++j) {
                if (paths[i][j] == ' ' || j == len - 1) {
                    if (j == len - 1) {
                        j++;
                    }
                    string word = paths[i].substr(pathPos + 1, j - 1 - pathPos);
                    int tmp = word.find('(');
                    string content = word.substr(tmp, word.length() - tmp);
                    mmap[content].push_back(path + "/" + word.substr(0, tmp));
                    pathPos = j;
                }
            }
        }
        vector<vector<string>> res;
        for (auto it = mmap.begin(); it != mmap.end(); ++it) {
            if (it->second.size() > 1) {
                res.push_back(it->second);
            }
        }
        return res;
    }
};


int main() {
    Solution solution;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    solution.findDuplicate(paths);
    return 0;
}