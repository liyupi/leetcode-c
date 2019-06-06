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
    class Node {
    public:
        map<char, Node*> children;
        bool word;

        Node() {
            word = false;
        }
    } *root;

    void add(const string &str) {
        int len = str.length();
        Node *node = root;
        for (int i = 0; i < len; ++i) {
            char c = str[i];
            if (!node->children[c]) {
                node->children[c] = new Node();
            }
            node = node->children[c];
        }
        node->word = true;
    }

    void init(vector<string> &dict) {
        root = new Node();
        int size = dict.size();
        for (int i = 0; i < size; ++i) {
            add(dict[i]);
        }
    }

    string addBoldTag(string s, vector<string> &dict) {
        init(dict);
        int len = s.length();
        string str;
        int left = -1;
        int right = -1;
        for (int i = 0; i < len; ++i) {
            Node *node = root;
            int pos = i;
            while(pos < len && node->children[s[pos]]) {
                node = node->children[s[pos]];
                pos++;
                if (node->word) {
                    if (left == -1) {
                        left = i;
                    }
                    right = max(right, pos);
                }
            }
            if (i >= right) {
                if (right != -1) {
                    str += "<b>" + s.substr(left, right - left) + "</b>";
                    right = -1;
                    left = -1;
                }
            }
            if (right == -1) {
                str += s[i];
            }
        }
        if (right != -1) {
            str += "<b>" + s.substr(left, right - left) + "</b>";
        }
        return str;
    }
};

int main() {
    Solution solution;
    vector<string> str = {"aaa","aab","bc","aaabbcc"};
    solution.addBoldTag("aaabbcc", str);
    return 0;
}